#include <string>
#include <iostream>

class Book : public LibraryMaterial
{
    private:
        std::string m_Author;
        std::string m_Genre;
        int m_Pages;

    public:
        Book(int id, std::string title, int year, std::string author, std::string genre, int pages)
        {
            this->m_Id = id;
            this->m_Title = title;
            this->m_Year = year;
            this->m_Author = author;
            this->m_Genre = genre;
            this->m_Pages = pages;
        }
        std::string GetTitle() const override
        {
            return this->m_Title;
        }

        void Display() override
        {
            std::cout << "ID: " << m_Id << "\nTitle: " << m_Title << "\nAuthor: " << m_Author << "\nGenre: " << m_Genre << "\nYear of Publication: " << m_Year << "\nNumber of m_Pages: " << m_Pages << "\n\n";
        }
};