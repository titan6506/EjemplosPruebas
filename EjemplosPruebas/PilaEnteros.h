#pragma once
#include <exception>
using namespace std;

class PilaEnteros
{
private:
	int* datos;
	int cantidad;
	int capacidad;

public:
	PilaEnteros(int capacidad)
	{
		this->capacidad = capacidad;
		this->datos = new int[capacidad];
		this->cantidad = 0;
	}

	bool estaVacia()
	{
		return this->cantidad == 0;
	}

	void push(int elemento)
	{
		this->datos[cantidad++] = elemento;
	}

	int pop()
	{
		if (!estaVacia()) {
			int resultado = this->datos[cantidad - 1];
			cantidad--;
			return resultado;
		}
		throw logic_error("La pila esta vacia. No se puede hacer pop.");
	}

	int getCantidad()
	{
		return this->cantidad;
	}


	~PilaEnteros()
	{
		delete[] this->datos;
	}
};
