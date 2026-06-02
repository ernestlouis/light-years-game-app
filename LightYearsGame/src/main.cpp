#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

#include "framework/Application.h"



int main()
{
 
	//Allocate Application on the heap using RAII
	auto app = std::make_unique<ly::Application>();
	
	app->Run();
  

   


}