#!/usr/bin/env bash
set -euo pipefail

# Safe cleanup: move existing build/ to a timestamped backup and create a fresh build/
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
BUILD_DIR="$ROOT/build"

if [ -d "$BUILD_DIR" ]; then
  TIMESTAMP=$(date +"%Y%m%d_%H%M%S")
  BACKUP_DIR="${ROOT}/build_backup_${TIMESTAMP}"
  echo "Moving existing build/ to ${BACKUP_DIR}"
  mv "$BUILD_DIR" "$BACKUP_DIR"
else
  echo "No build/ directory found. Nothing to move."
fi

mkdir -p "$BUILD_DIR"
echo "New empty build/ created at $BUILD_DIR"
