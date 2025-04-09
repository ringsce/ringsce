# Detect platform
UNAME_S := $(shell uname -s)
UNAME_M := $(shell uname -m)

# Platform flags
IS_MACOS_SILICON := $(filter arm64,$(UNAME_M))
IS_LINUX_ARM64   := $(and $(filter Linux,$(UNAME_S)),$(filter aarch64 arm64,$(UNAME_M)))

# Entry point source files
MAIN_1_SRC = $(KAYTE_REPO_DIR)/projects/kayte.lpr
MAIN_2_SRC = $(REPO_2_DIR)/tools/toolkit.lpr

# Output binaries
BIN_1 = $(KAYTE_REPO_DIR)/projects/kayte
BIN_2 = $(REPO_2_DIR)/tools/toolkit

# Repo definitions
KAYTE_REPO_URL = https://github.com/ringsce/kayte-lang.git
KAYTE_REPO_DIR = kayte-lang

REPO_EKRON_URL = https://github.com/ringsce/ekron-realms.git
REPO_EKRON_DIR = ekron-realms

REPO_TILDE_URL = https://github.com/ringsce/tilde-desktop.git
REPO_TILDE_DIR = tilde-desktop

# LLVM flags
LLVM_CFLAGS := -O2 -flto
LLVM_LD_FLAGS :=

ifeq ($(IS_MACOS_SILICON),arm64)
	LLVM_CC := clang
	LLVM_CXX := clang++
	LLVM_LD_FLAGS := -framework CoreFoundation
	LLVM_ENABLED := 1
endif

ifeq ($(IS_LINUX_ARM64),arm64)
	LLVM_CC := clang
	LLVM_CXX := clang++
	LLVM_ENABLED := 1
endif

# LLVM info
llvm-info:
ifeq ($(LLVM_ENABLED),1)
	@echo "🧠 LLVM is enabled!"
	@echo "🔧 Compiler: $(LLVM_CC)"
else
	@echo "🚫 LLVM not enabled on this platform."
endif

# Platform info
platform-info:
	@echo "Detected OS: $(UNAME_S)"
	@echo "Detected ARCH: $(UNAME_M)"
ifneq ($(strip $(IS_MACOS_SILICON)),)
	@echo "  ✅ macOS Silicon (arm64) detected"
endif
ifneq ($(strip $(IS_LINUX_ARM64)),)
	@echo "  ✅ Linux ARM64 detected"
endif

# Compiler
LAZBUILD_PATH ?= $(HOME)/fpcupdeluxe/lazarus/lazbuild
LAZBUILD = $(LAZBUILD_PATH)
FPC = $(LAZBUILD_PATH)

# Submodules
SUBMODULES = \
  tilde-desktop \
  ekron-realms \
  realms-rpi \
  ringsce-editor \
  morpheus \
  morpheus/gtk/webui/cpp-httplib

clone-submodules:
	@echo "🔁 Cloning submodules..."
	@for sub in $(SUBMODULES); do \
		if [ ! -d "$$sub/.git" ]; then \
			echo "➡️  Cloning $$sub..."; \
			git submodule update --init --recursive $$sub || echo "❌ Failed: $$sub"; \
		else \
			echo "✅ $$sub already exists."; \
		fi \
	done

git-update: clone-submodules
	@echo "🔄 Updating Git Submodules..."
	@git submodule update --init --recursive || echo "⚠️  Some submodules could not be updated."
	@for dir in $(SUBMODULES); do \
		if [ -d "$$dir/.git" ]; then \
			echo "🔁 Updating $$dir..."; \
			cd $$dir && git checkout main && git pull origin main || echo "⚠️  $$dir pull failed"; \
			cd - > /dev/null; \
		fi \
	done

# Clone targets
clone-ekron:
	@if [ ! -d "$(REPO_EKRON_DIR)" ]; then git clone $(REPO_EKRON_URL); fi
clone-tilde:
	@if [ ! -d "$(REPO_TILDE_DIR)" ]; then git clone $(REPO_TILDE_URL); fi
clone-kayte-lang:
	@if [ ! -d "$(KAYTE_REPO_DIR)" ]; then git clone $(KAYTE_REPO_URL); fi

# Build rules
build-kayte-lang:
	@echo "🔧 Building kayte-lang..."
	@chmod +x kayte-lang/projects/kayte.lpr
	@$(LAZBUILD) kayte-lang/projects/kayte.lpi || echo "❌ Failed to build kayte-lang"

build-tilde-desktop:
	@echo "🔧 Building tilde-desktop..."
	@if [ -f tilde-desktop/ctm-interpreter/ctminterpreter.lpi ]; then \
		$(LAZBUILD) tilde-desktop/ctm-interpreter/ctminterpreter.lpi ; \
	else \
		echo "⚠️  No ctminterpreter.lpi in tilde-desktop"; \
	fi

build-ekron-realms:
	@echo "🔧 Building ekron-realms..."
	@if [ -f ekron-realms/Projects/realms.lpi ]; then \
		$(LAZBUILD) ekron-realms/Projects/realms.lpi; \
	else \
		echo "⚠️  No realms.lpi in ekron-realms"; \
	fi

build-realms-rpi:
	@echo "🔧 Building realms-rpi..."
	@if [ -f realms-rpi/project.lpi ]; then \
		$(LAZBUILD) realms-rpi/project.lpi; \
	else \
		echo "⚠️  No project.lpi in realms-rpi"; \
	fi



build-submodules: build-kayte-lang build-realms-rpi build-tilde-desktop build-ekron-realms
	@echo "✅ All submodules built successfully."

# Archive output directory
RELEASE_DIR = release

# Archive target
package:
	@echo "📦 Packaging built binaries into tar.gz..."
	@mkdir -p $(RELEASE_DIR)/linux-arm64
	@mkdir -p $(RELEASE_DIR)/macos-arm64
	@mkdir -p $(RELEASE_DIR)/rpi3
	@mkdir -p $(RELEASE_DIR)/odroid-c2

	@if [ -f kayte-lang/projects/kayte ]; then cp kayte-lang/projects/kayte $(RELEASE_DIR)/linux-arm64/; fi
	@if [ -f ekron-realms/Projects/realms ]; then cp ekron-realms/Projects/realms $(RELEASE_DIR)/linux-arm64/; fi
	@tar -czvf ringsce-linux-arm64.tar.gz -C $(RELEASE_DIR)/linux-arm64 .

	@if [ -f kayte-lang/projects/kayte ]; then cp kayte-lang/projects/kayte $(RELEASE_DIR)/macos-arm64/; fi
	@if [ -f ekron-realms/Projects/realms ]; then cp ekron-realms/Projects/realms $(RELEASE_DIR)/macos-arm64/; fi
	@tar -czvf ringsce-macos-arm64.tar.gz -C $(RELEASE_DIR)/macos-arm64 .

	@if [ -f kayte-lang/projects/kayte ]; then cp kayte-lang/projects/kayte $(RELEASE_DIR)/rpi3/; fi
	@if [ -f ekron-realms/Projects/realms ]; then cp ekron-realms/Projects/realms $(RELEASE_DIR)/rpi3/; fi
	@tar -czvf ringsce-rpi3.tar.gz -C $(RELEASE_DIR)/rpi3 .

	@if [ -f kayte-lang/projects/kayte ]; then cp kayte-lang/projects/kayte $(RELEASE_DIR)/odroid-c2/; fi
	@if [ -f ekron-realms/Projects/realms ]; then cp ekron-realms/Projects/realms $(RELEASE_DIR)/odroid-c2/; fi
	@tar -czvf ringsce-odroid-c2.tar.gz -C $(RELEASE_DIR)/odroid-c2 .

	@echo "✅ Packages created: ringsce-*.tar.gz"


# Main build entry
build: build-submodules kayte-lang ekron-realms realms-rpi ringsce-editor package

# Clean
clean:
	@echo "🧹 Cleaning build artifacts..."
	@find . \( -name "*.o" -o -name "*.ppu" -o -name "*.compiled" -o -name "*.rst" -o -name "*.bak" \) -type f -delete
	@rm -f kayte-lang/projects/kayte
	@rm -f ekron-realms/tools/toolkit
	@rm -f ekron-realms/Projects/realms
	@rm -rf release
	@rm -f ringsce-*.tar.gz
	@echo "✅ Cleanup complete."


# Default
all: platform-info git-update llvm-info build

.PHONY: all git-update llvm-info build clean platform-info \
	clone-submodules clone-tilde clone-ekron clone-kayte-lang \
	build-submodules build-kayte-lang build-realms-rpi build-tilde-desktop build-ekron-realms
