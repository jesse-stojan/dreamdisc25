Rust scaffold for DreamDisk25

This folder contains a minimal Cargo workspace with two crates:

- `engine` — a small library crate that implements a minimal `Engine` struct and a unit test.
- `game` — a binary crate that depends on `engine` and runs a small prototype.

Build & test (inside the devcontainer):

```bash
cd rust
cargo build --workspace
cargo test -p engine
cargo run -p game
```

Notes:
- This scaffold is intentionally minimal to validate the Rust toolchain and an incremental migration workflow.
- Platform-specific/assembly third-party code (e.g., `third-party/sh4zam`) is left as-is for now and can be called from Rust via FFI if needed.
