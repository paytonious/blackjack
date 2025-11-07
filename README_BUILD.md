# Build & Cleanup helper

This repository uses CMake. The repository contains helper scripts to keep the workspace clean and to build easily.

Files added:
- `./.gitignore` — ignores `build/`, generated CMake files, binaries, and common temp files.
- `./scripts/clean_build.sh` — safely moves an existing `build/` to `build_backup_<timestamp>` and creates a fresh `build/` directory.
- `./scripts/build.sh` — runs `cmake` configure + build (parallel).

Quick usage (zsh):

# Make the scripts executable (only needed once)
# chmod +x scripts/*.sh

# Safely archive current build/ and create a new empty one
./scripts/clean_build.sh

# Configure and build
./scripts/build.sh

# Run the program
./build/blackjack

