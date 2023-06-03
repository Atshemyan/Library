#include "LibraryMaterial.hpp"
#include "Book.hpp"
#include "Journal.hpp"
#include "DVD.hpp"

class Library
{
    private:
        int FindAndGiveIndex(std::string title) const
        {
            for (int i = 0; i < m_Materials.size(); i++)
            {
                if (m_Materials[i]->GetTitle() == title)
                {
                    return i;
                }
                
            }

            return -1;
            
        }
        bool FindBorrowed(std::string NameToSearch)
        {
            for (int i = 0; i < m_BorrowedMaterials.size(); i++)
            {
                if(m_BorrowedMaterials[i]->GetTitle() == NameToSearch)
                {
                    return true;
                }
                
            }

            return false;
        }
        std::vector<LibraryMaterial*> m_BorrowedMaterials;
        std::vector<LibraryMaterial*> m_Materials; 
        unsigned int CountOfGivenBooks = 1;
        

    public:
        Library(){} 

        void AddMaterial(LibraryMaterial* NewMaterial) 
        {
            m_Materials.push_back(NewMaterial);
        }

        void DeleteMaterial(LibraryMaterial* NewMaterial) 
        {
            m_Materials.erase(remove(m_Materials.begin(), m_Materials.end(), NewMaterial));
        }
        bool find(std::string NameToSearch)
        {
            for (int i = 0; i < m_Materials.size(); i++)
            {
                if(m_Materials[i]->GetTitle() == NameToSearch)
                {
                    return true;
                }
                
            }

            return false;
        }

        Library operator=(const Library& rhs) = delete;
        Library operator=(const Library&& rhs) = delete;
        Library(const Library& rhs) = delete;
        Library(const Library&& rhs) = delete;


        LibraryMaterial* Borrow(std::string NameOfBook)
        {
            if (find(NameOfBook))
            {
                if (CountOfGivenBooks <= 3)
                {
                    ++CountOfGivenBooks;
                    LibraryMaterial* tmp = m_Materials[FindAndGiveIndex(NameOfBook)];
                    this->DeleteMaterial(tmp);
                    m_BorrowedMaterials.push_back(tmp);
                    return tmp;
                }
                else
                {
                    std::cout << "You cant Borrow this book, because you have so many books \n"; 
                }
            }
            else
            {
                std::cout << "You cant Borrow this book, because we haven't this book \n";
            }
            
            return nullptr;
        }

       void ReturnMaterial(LibraryMaterial* mtr)
       {
            if (!find(mtr->GetTitle()) && CountOfGivenBooks != 1 && FindBorrowed(mtr->GetTitle()))
            {
                --CountOfGivenBooks;
                this->AddMaterial(mtr);
                m_BorrowedMaterials.erase(remove(m_BorrowedMaterials.begin(), m_BorrowedMaterials.end(), mtr));
            }
            
            
       }

        void DisplayMaterials() //Function to Display all the m_Materials in the library
        { 
            for(int i = 0; i < m_Materials.size(); i++)
            {
                m_Materials[i]->Display();
            }
        }
};
