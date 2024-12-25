# Common definitions for the various Makefiles which set cuda settings
# No rules are defined here so this is safe to include at the beginning of other makefiles

ifeq ($(OS),linux)
	ifeq ($(wildcard /opt/musa),)
		MUSA_PATH ?= /usr/local/musa
	else
		MUSA_PATH ?= /opt/musa
	endif
	MUSA_COMPILER:=$(MUSA_PATH)/bin/mcc
endif
