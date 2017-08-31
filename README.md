# DBE

A project that aims to create a small simple database engine. 



## Class Breakdown

### Json Library

json11 was the library that I chose to easily export and import the database onto a json.

Its files are:

```
json11.hpp
json11.cpp
```

[GitHub json11 repository.](https://github.com/dropbox/json11)

#### Tabla.h

The tables have a header that includes the following attributes and methods:

```c++
char * nombre;
int id;
int primerBloqueCampo;
int actualBloqueCampo;
int primerBloqueReg;
int actualBloqueReg;

int cantCampos;
int cantReg;

int cantBloqueCampos;
int cantBloqueReg;
bool campoSpace(Campo *);
void addCampo(char* nombre, int tipo, BloqueMaster * bm);

void addRegistro(char * data, BloqueMaster * bm);
char * generateReg();
int tamReg();

Json registrosToJson();
Json camposToJson();
Json tablaToJson();

char * toChar();
void loadTabla(char*);

void loadCampos();
void loadRegs();
```

Through its attributes it is able to manage the relative physical location of the blocks that store its fields and entries. 

#### Campo.h

A class that represents a field of a table. It can be one of two types: int or char[20]. Its attributes are:

```c++
char * nombre;
int tipo;
int regSize;
```

#### Registro.h

A class that represents an entry of a table. Its information is stored as binary data directly as a char *. This is done to ease the writing process. However to be able to properly read the entry it uses the class Celda.h that interprets the data according to the field it represents.

```c++
char * data;
int len;
```

#### Celda.h

This class is used to properly read the entries of a table. It has a pointer to its corresponding field.

```c++
Campo * campo;
char * data;
```



###Blocks

We used blocks to store our database data. The classes that are written as blocks are:

```
Bloque.h
|_ BloqueMaster.h
|_ BloqueTabla.h
|_ BloqueCampo.h
|_ BloqueRegistro.h
```

#### Bloque.h

This class passes down three essential attributes, methods, and its constructor to its children. Blocks are the only classes that are directly written on disk.

```c++
int sig;	//The number of its next same type block
int num;	//Number of the block, which also represents its relative physical location
int sizeB; 	//Size of the Block

char * toChar();
void load(char* data);

void write();
void read();
```

#### BloqueMaster.h 

This class contains the attributes that manages the relative physical location of the total number of blocks and BloqueTabla. Its attributes are:

```c++
int primerBloqueTabla;
int actualBloqueTabla;
int cantTablas;
int cantBloqueTabla;
int cantBloques;
```

#### BloqueTabla.h

This class stores the tables to be written in secondary memory. Its primary function is to be able to read and write tables onto secondary memory. Its methods are:

```c++
bool addTabla(Tabla*);
```

#### BloqueCampo.h

This class stores the fields of a table to be written in secondary memory. Its methods are:

```c++
bool addCampo(Campo*);
```

#### BloqueRegistro.h

This class stores the entries of a table to be written in secondary memory. Its methods are:

```c++
bool addReg(Registro * r);
```

#### Engine.h

This is the class that manages the entire database and its tables. It is able to create tables, add fields to a table, add entries to a table and erase the database. In its constructor it automatically loads the database from disk, and also is able to be exported onto a json and imported from a json. These are its attributes and methods:

```c++
void format();
void load();
void addTabla(char* nombre);
void addCampoToTabla(int idTabla, char * nombre, int tipo);
void addRegistroToTabla(int idTabla, char * data = 0);

Tabla * searchTabla(int id);
BloqueTabla * searchBloqueTabla(int id);

void writeJson();
void readJson();

void loadTablas();
```