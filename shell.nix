let
  nixpkgs = fetchTarball "https://github.com/NixOS/nixpkgs/tarball/nixos-25.11";
  pkgs = import <nixpkgs> {config = {}; overlays = []; };
in
  pkgs.mkShell {
	packages = [
	  (
		pkgs.cmake
		  pkgs.ninja
		  pkgs.gcc
		  pkgs.python3.withPackages (python-pkgs: [
			python-pkgs.numpy
		  ])
	  )
	];
  }
