# Detect platform
UNAME_S := $(shell uname -s)
UNAME_M := $(shell uname -m)

# Platform flags
IS_MACOS_SILICON := $(filter arm64,$(UNAME_M))
IS_LINUX_ARM64   := $(and $(filter Linux,$(UNAME_S)),$(filter aarch64 arm64,$(UNAME_M)))

# Makefile for downloading multiple repos and building Kayte Lang projects

# Repositories
#REPO_1_URL = https://github.com/ringsce/kayte-lang.git
REPO_2_URL = https://github.com/ringsce/ekron-realms.git
REPO_3_URL = https://github.com/ringsce/kayte-vscode.git
REPO_4_URL = https://github.com/ringsce/tilde-desktop.git
REPO_5_URL = https://github.com/ringsce/ringsce.git

# Local clone directories
REPO_1_DIR = kayte-lang
REPO_2_DIR = ekron-realms
REPO_3_DIR = kayte-vscode
REPO_4_DIR = tilde-desktop

# Entry point source files to compile
MAIN_1_SRC = $(REPO_1_DIR)/projects/kayte.lpr
MAIN_2_SRC = $(REPO_2_DIR)/tools/toolkit.lpr

# Output binaries
BIN_1 = $(REPO_1_DIR)/projects/kayte
BIN_2 = $(REPO_2_DIR)/tools/toolkit


# Define repo and directory
KAYTE_REPO_URL = https://github.com/ringsce/kayte-lang.git
KAYTE_REPO_DIR = kayte-lang

REPO_EKRON_URL = https://github.com/ringsce/ekron-realms.git
REPO_EKRON_DIR = ekron-realms


# Clone ekron realms if it doesn't exist
clone-ekron:
	@if [ ! -d "$(REPO_EKRON_DIR)" ]; then \
		echo "🚀 Cloning Ekron..."; \
		git clone $(REPO_EKRON_URL) $(REPO_EKRON_DIR); \
	else \
		echo "✅ Ekron Realms already cloned."; \
	fi


# Clone kayte-lang if it doesn't exist
clone-kayte-lang:
	@if [ ! -d "$(KAYTE_REPO_DIR)" ]; then \
		echo "🚀 Cloning Kayte Lang..."; \
		git clone $(KAYTE_REPO_URL) $(KAYTE_REPO_DIR); \
	else \
		echo "✅ Kayte Lang already cloned."; \
	fi

# Compiler
FPC = fpc

# All target
all: git-update build

platform-info:
	@echo "Detected OS: $(UNAME_S)"
	@echo "Detected ARCH: $(UNAME_M)"
ifneq ($(strip $(IS_MACOS_SILICON)),)
	@echo "  Building on macOS Silicon (arm64)"
endif
ifneq ($(strip $(IS_LINUX_ARM64)),)
	@echo " Building on Linux ARM64"
endif

# Submodules
SUBMODULES = ekron-realms morpheus realms-rpi ringsce-editor

git-update:
	@echo "🔄 Updating Git Submodules..."
	@if [ -f .gitmodules ]; then \
		if git config --file .gitmodules --get-regexp '^submodule\..*\.url' > /dev/null 2>&1; then \
			git submodule update --init --recursive || echo "⚠️  Some submodules could not be updated. Skipping..."; \
		else \
			echo "⚠️  No valid submodule URLs found in .gitmodules. Skipping suamkebmodule update."; \
		fi \
	else \
		echo "⚠️  No .gitmodules file found. Skipping submodule update."; \
	fi

	@for dir in $(SUBMODULES); do \
		if [ -d "$$dir/.git" ]; then \
			echo "🔁 Updating $$dir..."; \
			cd $$dir; \
			git checkout main || echo "⚠️  $$dir: 'main' branch not found"; \
			git pull origin main || echo "⚠️  $$dir: pull failed"; \
			cd - > /dev/null; \
		fi \
	done



# Clone or update all repositories
#git-update: git-update-1 git-update-2 git-update-3 git-update-4

git-update-1:
	@if [ -d "$(REPO_1_DIR)" ]; then \
		echo "Updating $(REPO_1_DIR)..."; \
		cd $(REPO_1_DIR) && git pull; \
	else \
		echo "Cloning $(REPO_1_DIR)..."; \
		git clone $(REPO_1_URL) $(REPO_1_DIR); \
	fi

git-update-2:
	@if [ -d "$(REPO_2_DIR)" ]; then \
		echo "Updating $(REPO_2_DIR)..."; \
		cd $(REPO_2_DIR) && git pull; \
	else \
		echo "Cloning $(REPO_2_DIR)..."; \
		git clone $(REPO_2_URL) $(REPO_2_DIR); \
	fi

git-update-3:
	@if [ -d "$(REPO_3_DIR)" ]; then \
		echo "Updating $(REPO_3_DIR)..."; \
		cd $(REPO_3_DIR) && git pull; \
	else \
		echo "Cloning $(REPO_3_DIR)..."; \
		git clone $(REPO_3_URL) $(REPO_3_DIR); \
	fi


git-update-4:
	@if [ -d "$(REPO_4_DIR)" ]; then \
		echo "Updating $(REPO_4_DIR)..."; \
		cd $(REPO_4_DIR) && git pull; \
	else \
		echo "Cloning $(REPO_4_DIR)..."; \
		git clone $(REPO_4_URL) $(REPO_4_DIR); \
	fi

git-update-5:
	@if [ -d "$(REPO_5_DIR)" ]; then \
		echo "Updating $(REPO_5_DIR)..."; \
		cd $(REPO_5_DIR) && git pull; \
	else \
		echo "Cloning $(REPO_5_DIR)..."; \
		git clone --recurse-submodules $(REPO_5_URL) $(REPO_5_DIR); \
	fi

# Build all main .lpr files
build: build-1 build-2 build-3 build-4 build-5

build-1:
	$(FPC) -MObjFPC -Sh $(MAIN_1_SRC)

build-2:
	$(FPC) -MObjFPC -Sh $(MAIN_2_SRC)

build-3:
	$(FPC) -MObjFPC -Sh $(MAIN_3_SRC)

build-4:
	$(FPC) -MObjFPC -Sh $(MAIN_4_SRC)

# Clean up build files
clean:
	@echo "Cleaning..."
	find $(REPO_1_DIR) $(REPO_2_DIR) $(REPO_3_DIR) $(REPO_4_DIR) -name "*.o" -o -name "*.ppu" -delete
	rm -f $(BIN_1) $(BIN_2) $(BIN_3)

.PHONY: all git-update git-update-1 git-update-2 git-update-3 git-update-4 build build-1 build-2 build-3 build-4 clean

