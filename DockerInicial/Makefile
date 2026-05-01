#==============================================================================
# CONFIGURACIÓN DE RUTAS
#==============================================================================
CXX      := g++
CXXFLAGS := -std=c++23 -O3 -Wall

SRC_DIR     := src
SCRIPT_DIR  := scripts

#Se crean automaticamente hasta compilar y ejecutar
OBJ_DIR     := obj
BIN_DIR     := bin
OUT_DIR     := output

# Archivos de Compilación
APP         := $(BIN_DIR)/julia
SOURCES     := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS     := $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Archivos de Proceso
GP_SCRIPT   := $(SCRIPT_DIR)/julia_set.gp
DATA_FILE   := $(OUT_DIR)/julia_set.txt
IMAGE_FILE  := $(OUT_DIR)/julia_set.png

#==============================================================================
# REGLAS DE EJECUCIÓN
#==============================================================================
all: prepare $(APP) run plot show_info

.PHONY: all prepare run plot clean show_info

# Crea la estructura de carpetas
prepare:
	@mkdir -p $(OBJ_DIR) $(BIN_DIR) $(OUT_DIR) $(SCRIPT_DIR)

# Compilación: guarda el .o en la carpeta obj[cite: 1, 4]
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "  [CC]  $< -> $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Enlazado: guarda el ejecutable en la carpeta bin[cite: 1, 4]
$(APP): $(OBJECTS)
	@echo "  [LD]  Creando binario: $@"
	@$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(APP)

# Ejecución: usa la ruta de bin/julia
run: $(APP)
	@echo "  [RUN] Generando datos en $(DATA_FILE)..."
	@./$(APP)

# Gnuplot: procesa el script[cite: 1, 5]
plot: $(DATA_FILE)
	@echo "  [GP]  Procesando script: $(GP_SCRIPT)..."
	@gnuplot $(GP_SCRIPT)

show_info:
	@echo "-------------------------------------------------------"
	@echo "✅ Proceso Finalizado."
	@echo "📂 Binario: $(APP)"
	@echo "🖼️  Imagen:  $(IMAGE_FILE)"
	@echo "-------------------------------------------------------"

clean:
	@echo "  [CLEAN] Borrando carpetas generadas..."
	@rm -rf $(OBJ_DIR) $(BIN_DIR) $(OUT_DIR) julia_set.txt julia