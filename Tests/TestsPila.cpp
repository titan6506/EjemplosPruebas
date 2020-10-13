#include "pch.h"
#include "CppUnitTest.h"
#include "../EjemplosPruebas/PilaEnteros.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(TestsPila)
	{
	private:
		PilaEnteros* pila;


	public:
		TEST_METHOD_INITIALIZE(methodInitialize)
		{
			pila = new PilaEnteros(8);
		}

		TEST_METHOD_CLEANUP(methodCleanup)
	    {
			delete this->pila;
		}

		TEST_METHOD(pilaEmpiezaVacia)
		{
			Assert::IsTrue(pila->estaVacia());
		}

		TEST_METHOD(cantidadReflejaNumeroElementosAgregados)
		{
			pila->push(2);
			pila->push(3);
			pila->push(4);
			pila->push(5);
			Assert::AreEqual(4, pila->getCantidad());
		}

		TEST_METHOD(ultimoEntrarEsUltimoEnSalir)
	    {
			int elementoIngresado = 2;
			pila->push(elementoIngresado);
			
			int elementoRecuperado = pila->pop();
			Assert::AreEqual(elementoIngresado, elementoRecuperado);
		}

		TEST_METHOD(hacerPopCuandoLaPilaEstaVaciaLanzaExcepcion)
		{
			Assert::ExpectException<logic_error>([this]() { pila->pop(); });
		}

        // Otros tests -- ejercicios
		// Si se acaba la capacidad se tira una excepci�n.
		// Si hay m�s de un elemento, entonces la pila no est� vac�a
		// Si se meten 4 elementos y se sacan, son los mismos en orden inverso.

	};
}
