# Declare phony targets so Make always runs them even if files with these names exist.
.PHONY: clean clean-dry

# Explicit list of directories to clean (add new lesson folders here as you add them).
DIRS := \
	000-template \
	001-gdb-lldb-debugging \
	002-compiler-linker/01-single-step \
	002-compiler-linker/02-separate-steps \
	002-compiler-linker/03-linker-error \
	002-compiler-linker/04-include-h-file \
	003-std-cout-cin \
	004-vscode-build-run \
	005-sfml-homebrew-setup \
	006-clang-save-temps \
	007-webgpu-cross-platform-app \
	008-webgpu-wgsl \
	009-int-main-no-return \
	010-ub-for-uninitialized-var \
	011-lldb-init-settings \
	012-counting-bits \
	013-header-files/01-inline \
	013-header-files/02-separate-header \
	013-header-files/03-inline-multiple \
	013-header-files/04-separate-header-multiple \
	014-vscode-debug \
	015-ptr-vs-ref-for-output \
	016-array-data-init \
	017-reading-assembly \
	018-indirect-memory-addressing \
	019-stack-frames \
	020-stack-frame-red-zone \
	021-lldb-debugging \
	021-lldb-stepping-commands \
	022-program-counter \
	023-xorl-eax-eax \
	024-lldb-p-x-commands \
	025-asserts \
	026-size_t \
	027-size_t-vec-size-minus-one \
	028-att-vs-intel-syntax \
	029-timestamp-data-type \
	030-civ-ii-gandhi \
	031-references \
	032-pass-by-reference \
	033-vector-of-bools \
	034-pre-vs-post-increment \
	035-for-loop-pre-vs-post-incr \
	036-threads-intro \
	037-threads-join-or-detach \
	038-threads-mutex \
	039-threads-mutex-data-race \
	040-threads-mutex-vs-atomic \
	041-threads-mutex-lock-guard \
	042-threads-mutex-deadlock \
	043-threads-mutex-scoped-lock \
	044-threads-mutex-unique-lock \
	045-threads-mutex-producer-consumer \
	046-constructors \
	047-compiler-optimizations \
	048-wall-wextra-werror \
	049-static-vs-dynamic-linking \
	050-compiler-linking \
	051-static-variables \
	052-static-var-dynamic-init \
	053-include-string-optional \
	054-dont-use-namespace \
	099-using-namespace-std-maybe

# Build artifacts to remove inside each directory in DIRS (add more names/extensions here anytime).
ARTIFACTS := \
	build \
	main main-01 main-02 main-03 a.out \
	01-cout 02-cin-bool 03-cin-string \
	*.dSYM *.o *.s *.ii *.bc main.ast *.ll

# Preview existing build artifacts that `make clean` would delete (nothing is removed).
clean-dry:
	@for dir in $(DIRS); do \
		for match in $(addprefix $$dir/,$(ARTIFACTS)); do \
			if [ -e "$$match" ]; then echo "$$match"; fi; \
		done; \
	done

# Remove all matching build artifacts from every directory in DIRS.
clean:
	@for dir in $(DIRS); do \
		echo "Cleaning $$dir"; \
		rm -rf $(addprefix $$dir/,$(ARTIFACTS)); \
	done
