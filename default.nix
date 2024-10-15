{pkgs ? import <nixpkgs> {}}:
pkgs.mkShell {
  packages = with pkgs; [
    # QMK command-line and dependencies.
    qmk

    # Edit nix files.
    nixd
    alejandra
  ];
}
