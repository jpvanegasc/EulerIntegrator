.DEFAULT_GOAL := help

# Python venv for pre-commit
VENV_DIR ?= .venv
VENV_ACTIVATE = $(VENV_DIR)/bin/activate
VENV_RUN = . $(VENV_ACTIVATE);

$(VENV_DIR):
	test -d $(VENV_DIR) || python3 -m venv $(VENV_DIR)
.PHONY:
.SILENT:

lint: $(VENV_DIR) ## Run linters via pre-commit
	$(VENV_RUN) pre-commit run --all-files

help: ## Show this help message
	grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'