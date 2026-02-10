define template_mk

# Name and directories
$(1)_BIN := $(1)
$(1)_DIR := $(2)

# Object files
$(1)_C_FILES := $$(shell find $$($(1)_DIR) -name "*.c")
$(1)_O_FILES := $$(foreach x,$$($(1)_C_FILES),$$(patsubst $$($(1)_DIR)/%,$$(BUILD_DIR)/%,$$(x)))
$(1)_O_FILES := $$(foreach x,$$($(1)_O_FILES),$$(patsubst %.c,%.o,$$(x)))
$(1)_D_FILES := $$($(1)_O_FILES:%.o=%.d)

# Include directories
$(1)_INCLUDE_DIR := $$($(1)_DIR) $$(SRC_DIR) $$(BUILD_DIR) $$(BUILD_DIR)

# Generate include directory argument
$(1)_INCLUDES := $$(foreach x,$$($(1)_INCLUDE_DIR),$$(addprefix -I,$$(x)))

# GCC -MMD glory!
-include $$($(1)_D_FILES)

$$(BUILD_DIR)/%.d: $$($(1)_DIR)/%.c | $$(BUILD_DIR)
	mkdir -p $$(dir $$@)
	$$(CC) $$($(1)_INCLUDES) $$(CFLAGS) -MM -c $$< -MF $$@

$$(BUILD_DIR)/%.o: $$($(1)_DIR)/%.c | $$(BUILD_DIR)
	mkdir -p $$(dir $$@)
	$$(CC) $$($(1)_INCLUDES) $$(CFLAGS) -MMD -c $$< -o $$@

$$(BUILD_DIR)/$$($(1)_BIN): $$($(1)_O_FILES) | $$(BUILD_DIR)
	$$(CC) $$($(1)_O_FILES) $$(IFLAGS) -o $$@

$(1): $$(BUILD_DIR)/$$($(1)_BIN)

clean_$(1):
	rm -f  $$($(1)_O_FILES)
	rm -f  $$($(1)_D_FILES)
	rm -f  $$(BUILD_DIR)/$$($(1)_BIN)

.PHONY: clean_$(1) $(1)

endef
