## me crea obj si no se ha creado anteriormente 

################################################
############ MACROS ############################
################################################


#$(1) : Compiler
#$(2) : Object Files to generate. 
#$(3) : Source Files
#$(4) : Additional dependencies. 
#$(5) : Flags. 

define COMPILE

$(2) : $(3) $(4)
	$(1) -c -o $(2) $(3) $(5)

endef

#$(1) : Source File. 
#Generar los ficheros src/ por obj/ 
#---------> src/fichero.cpp
#---------> obj/fichero.o
#tambien verifico que los .c tambien sean .o 
#%-> para todo SRC .. LO QUE SEA.... 

define C2O
$(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(patsubst $(SRC)%,$(OBJ)%,$(1))))
endef

#$(1) : Source File. 
#Generar los ficheros src/ por obj/ 
#---------> src/fichero.cpp
#---------> src/fichero.h
#tambien verifico que los .c tambien sean .h 

define C2H
$(patsubst %.c,%.h,$(patsbust %.cpp,%.hpp,$(1)))
endef



################################################
########## CONFIG ##############################
################################################






APP     := game
CCFLAGS := -Wall -pedantic##Comment flags. 
CFLAGS  := $(CCFLAGS)
CC      := g++ -std=c++17 ##Compilers. c++
C       := gcc	##Compilador de C 
MKDIR   := mkdir -p  ## Me permite crear carpetas padres. y la creo solo cuando no exista. 

LIBS    := lib
SRC     := src
OBJ     := obj
LIB     := lib/tinyPTC/libtinyptc.a lib/picoPNG/libpicoPNG.a -lX11 

INCLUDEDIRS := -I$(SRC) -I$(LIBS)

ifdef DEBUG
  	CCFLAGS += -g 
	CFLAGS  += -g
else ifdef SANITIZE
	CCFLAGS += -fsanitize=address -fno-omit-frame-pointer -O1 -g
	CFLAGS  += -fsanitize=address -fno-omit-frame-pointer -O1 -g
else 
	CCFLAGS += -O3
	CFLAGS  += -O3
endif



ALLCS       :=		$(shell find $(SRC)/ -type f -iname *.c)
ALLCPPS     :=    $(shell find $(SRC)/ -type f -iname *.cpp)
ALLCSOBJ    :=    $(patsubst %.c,%.o,$(ALLCS))
ALLOBJ      :=    $(foreach F,$(ALLCPPS) $(ALLCS),$(call C2O,$(F)))
SUBDIRS 	   :=    $(shell find $(SRC)/ -type d )        ## Me llevo los subidrectorios y genero scripting con shell 
OBJSUBDIRS  :=		$(patsubst $(SRC)%,$(OBJ)%,$(SUBDIRS))         ##En subdirs, lo que veas en SRC , lo vas a cambiar por OBJ .. 
.PHONY: dir libs libs-cleanall                                   

## Se utiliza para no generar una salida simplemente ya que siempre se lanzaria 

##el -c me dice que tiene que compilar ambos main.o y main cpp , pero no te crea main.o, para crear el .o se pone -o


$(APP) : $(OBJSUBDIRS) $(ALLOBJ)
	$(CC) -o $(APP) $(ALLOBJ) $(LIB) 
	# EN ALLCPPSOBJ Y ALLCSOBJ LO QUE VEAS CON SRC , LO CAMBIAS POR OBJ 
	##depende Game depende main.cpp y cada vez que cambien lo construyo.1.Genero Directorio 2. Genero los .o 3.y se bus
	#$(CC) $(SRC)/main.cpp -c -o obj/main.o $(CCFLAGS) 
	##comando para construir.  y generamos en obj que ya ha sido creado 

#para todo .o hay una dependencia .c , NOS PERMITE BUSCAR LOS OBJ EN OBJ, Y EN SRC por si cambian y no poner todos 

#De esta forma, para cada F va a coger el fichero cpp y va hacer las  llamadas para poder compilar 
#$(foreach F,$(ALLCPPS),$(eval $(call COMPILE,$(CC),$(call C2O,$(F)),$(F),$(call C2H,$(F)),$(CCFLAGS))))

$(foreach F,$(ALLCPPS),$(eval $(call COMPILE,$(CC),$(call C2O,$(F)),$(F),$(call C2H,$(F)),$(CCFLAGS) $(INCLUDEDIRS))))
$(foreach F,$(ALLCS),$(eval $(call COMPILE,$(C),$(call C2O,$(F)),$(F),$(call C2H,$(F)),$(CFLAGS) $(INCLUDEDIRS))))

#$(OBJ)/%.o : $(SRC)/%.c               
#	$(C) -o $(patsubst $(SRC)%,$(OBJ)%,$@) -c $^ $(CFLAGS)

#$(OBJ)/%.o : $(SRC)/%.cpp               
#	$(CC) -o $(patsubst $(SRC)%,$(OBJ)%,$@) -c $^ $(CCFLAGS)

dir:
	$(info $(SUBDIRS))
	$(info $(OBJSUBDIRS))
	$(info $(ALLCPPS))
	$(info $(ALLCS))
	$(info $(ALLCSOBJ))


$(OBJSUBDIRS) : 
	$(MKDIR) $(OBJSUBDIRS)


## CLEAN rules
clean:
	$(RM) -r "./$(OBJ)"

cleanall: clean
	$(RM) "./$(APP)"

libs:
	$(MAKE) -C $(LIBS)

libs-cleanall:
	$(MAKE) -C $(LIBS) cleanall

