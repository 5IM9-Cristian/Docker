#==============================================================================
# CONFIGURACIÓN DE RUTAS
#==============================================================================
CC       := gcc
CFLAGS   := -O3 -Wall

SRC_DIR  := src
DATA_DIR := data
OBJ_DIR  := obj
BIN_DIR  := bin
OUT_DIR  := output

# Archivos de Compilación
APP      := $(BIN_DIR)/burbuja
SOURCES  := $(wildcard $(SRC_DIR)/*.c)
OBJECTS  := $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Archivos de Proceso
INPUT_FILE  := $(DATA_DIR)/Numeros.txt
OUTPUT_FILE := $(OUT_DIR)/ordenados.txt

#==============================================================================
# REGLAS DE EJECUCIÓN
#==============================================================================
all: prepare $(APP) run show_info

.PHONY: all prepare run clean show_info

# Crea la estructura de carpetas si no existe
prepare:
	@mkdir -p $(OBJ_DIR) $(BIN_DIR) $(OUT_DIR) $(DATA_DIR)

# Compilación de objetos
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "  [CC]  $< -> $@"
	@$(CC) $(CFLAGS) -c $< -o $@

# Enlazado del binario
$(APP): $(OBJECTS)
	@echo "  [LD]  Creando binario: $@"
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(APP)

# Ejecución del programa
run: $(APP)
	@echo "  [RUN] Ordenando números de $(INPUT_FILE)..."
	@./$(APP)

show_info:
	@echo "-------------------------------------------------------"
	@echo "✅ Proceso Finalizado."
	@echo "📂 Binario: $(APP)"
	@echo "📄 Resultado: $(OUTPUT_FILE)"
	@echo "-------------------------------------------------------"

clean:
	@echo "  [CLEAN] Borrando carpetas generadas..."
	@rm -rf $(OBJ_DIR) $(BIN_DIR) $(OUT_DIR)