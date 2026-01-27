#!/usr/bin/env python3
import os
import subprocess
import shutil
import json
from pathlib import Path

APP_NAME = "Mariner"
DYLIB_FILENAME = "libMariner.dylib"


def RunCMake():
    script_dir = Path(__file__).resolve().parent
    build_dir = script_dir / "build"

    shutil.rmtree(build_dir, ignore_errors=True)
    build_dir.mkdir(parents=True, exist_ok=True)

    subprocess.run(["cmake", ".."], cwd=build_dir, check=True)
    subprocess.run(["cmake", "--build", "."], cwd=build_dir, check=True)

    CreateAppBundle(script_dir, build_dir)
    return 0


def is_macho_executable(path: Path) -> bool:
    result = subprocess.run(
        ["file", str(path)],
        capture_output=True,
        text=True,
        check=True,
    )
    return "Mach-O" in result.stdout and "executable" in result.stdout


def FixDylibLinking(app_bundle: Path):
    macos_dir = app_bundle / "Contents" / "MacOS"
    frameworks_dir = app_bundle / "Contents" / "Frameworks"
    dylib = frameworks_dir / DYLIB_FILENAME

    subprocess.run(
        ["install_name_tool", "-id", f"@rpath/{DYLIB_FILENAME}", str(dylib)],
        check=True,
    )

    for exe in macos_dir.iterdir():
        if not exe.is_file():
            continue

        subprocess.run(
            [
                "install_name_tool",
                "-add_rpath",
                "@executable_path/../Frameworks",
                str(exe),
            ],
            check=True,
        )

        subprocess.run(
            [
                "install_name_tool",
                "-change",
                str(dylib),
                f"@rpath/{DYLIB_FILENAME}",
                str(exe),
            ],
            check=False,
        )


def CreateAppBundle(script_dir: Path, build_dir: Path):
    out_dir = script_dir / "out"
    app_bundle = out_dir / f"{APP_NAME}.app"
    contents = app_bundle / "Contents"
    macos_dir = contents / "MacOS"
    resources_dir = contents / "Resources"
    frameworks_dir = contents / "Frameworks"

    shutil.rmtree(app_bundle, ignore_errors=True)
    macos_dir.mkdir(parents=True, exist_ok=True)
    resources_dir.mkdir(parents=True, exist_ok=True)
    frameworks_dir.mkdir(parents=True, exist_ok=True)

    executables = []

    for file in build_dir.iterdir():
        if file.is_file() and is_macho_executable(file):
            target = macos_dir / file.name
            shutil.copy2(file, target)
            target.chmod(0o755)
            executables.append(target)

    if not executables:
        raise RuntimeError("No Mach-O executables found")

    dylib_src = build_dir / DYLIB_FILENAME
    if not dylib_src.exists():
        raise FileNotFoundError(DYLIB_FILENAME)

    dylib_dst = frameworks_dir / DYLIB_FILENAME
    shutil.copy2(dylib_src, dylib_dst)
    dylib_dst.chmod(0o755)

    FixDylibLinking(app_bundle)

    info_plist = contents / "Info.plist"
    info_plist.write_text(
        f"""<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN"
"http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
  <dict>
    <key>CFBundleName</key>
    <string>{APP_NAME}</string>
    <key>CFBundleExecutable</key>
    <string>{executables[0].name}</string>
    <key>CFBundleIdentifier</key>
    <string>com.example.{APP_NAME.lower()}</string>
    <key>CFBundlePackageType</key>
    <string>APPL</string>
    <key>CFBundleVersion</key>
    <string>1.0</string>
  </dict>
</plist>
""",
        encoding="utf-8",
    )

    with (resources_dir / "Flags.json").open("w", encoding="utf-8") as f:
        json.dump({}, f, indent=2)

    out_dir.mkdir(parents=True, exist_ok=True)


def main():
    return RunCMake()


if __name__ == "__main__":
    raise SystemExit(main())
