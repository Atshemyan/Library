#include "Library.hpp"
int main()
{
    Library myLibrary;
    
    Book b1(1, "FirstBook", 1777, "Donald Knuth", "Computer Science", 232);
    Book b2(2, "SecondBook", 1666, "Hayk Darbinyan","Computer Science", 288);

    Journal j1(3, "Porsche", 2020, 587, 7835, "");
    Journal j2(4, "BMW", 2020, 369, 6509, "");

    DVD d1(5, "The Godfather", 1972, "Francis Ford Coppola", 175);

    myLibrary.AddMaterial(&b1);
    myLibrary.AddMaterial(&b2);

    myLibrary.AddMaterial(&j1); 
    myLibrary.AddMaterial(&j2);

    myLibrary.AddMaterial(&d1);

    myLibrary.DeleteMaterial(&j1);

    
    myLibrary.Borrow("The Godfather")->Display();
    myLibrary.Borrow("BMW")->Display();
    myLibrary.ReturnMaterial(myLibrary.Borrow("SecondBook"));
    myLibrary.Borrow("FirstBook")->Display();


    

    // myLibrary.DisplayMaterials(); //Displaying all the materials in the library
    

    return 0;
}
