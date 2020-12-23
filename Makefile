include CONFIG.cfg

CC = gcc
LD = gcc
CFLAGS = 
CPPFLAGS = 
LDFLAGS =

INPUT_FILE_TYPE = in
OUTPUT_FILE_TYPE = out
LOG_FILE_TYPE = log

EXEC = $(BUILD_DIR)/$(NAME)
OBJECTS = $(BUILD_DIR)/sorter.o $(BUILD_DIR)/handler.o $(BUILD_DIR)/validate.o
DEPS = $(OBJECTS:.o=.d)
LOGS = $(patsubst $(TEST_DIR)/%.$(INPUT_FILE_TYPE), $(TEST_DIR)/%.$(LOG_FILE_TYPE), $(wildcard $(TEST_DIR)/*.$(INPUT_FILE_TYPE)))

.PHONY: all check clean


all: $(EXEC) 

$(EXEC): $(OBJECTS)
	$(LD) $(LDFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

-include $(DEPS)

$(BUILD_DIR):
	mkdir -p $@

check: $(LOGS)
	@for log in $^ ; do \
        if [ "$$(cat $${log})" != "PASSED" ] ; then \
            exit 1 ; \
        fi ; \
    done

$(TEST_DIR)/%.$(LOG_FILE_TYPE): $(TEST_DIR)/%.$(INPUT_FILE_TYPE) $(TEST_DIR)/%.$(OUTPUT_FILE_TYPE) $(EXEC)
	python3 test.py $^


clean:
	$(RM) $(EXEC) $(OBJECTS) $(DEPS) $(MAIN_LOG) $(LOGS)
	
