SOURCES = $(shell find -type f -name "*.c")
OBJECTS = $(SOURCES:%.c=%.o)

dijkstra.out: $(OBJECTS)
	@echo "Link completo."
	@gcc -o $@ $^ -Wall -g -lm

%.o: %.c
	@echo "Arquivo $< completo."
	@gcc -c -o $@ -Wall -g -lm $<

.PHONY: clean
clean:
	@echo "Limpeza concluida"
	@rm -rf $(OBJECTS)