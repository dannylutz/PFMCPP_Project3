{ pkgs }: {
	deps = [
   pkgs.pick
		pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}