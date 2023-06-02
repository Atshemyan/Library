class DVD : public LibraryMaterial
{
    private:
        std::string m_Director; // Name
        int m_Duration; //Duration of the DVD in minutes

    public:
        DVD(int id, std::string title, int year, std::string director, int duration)
        { 
            this->m_Id = id;
            this->m_Title = title;
            this->m_Year = year;
            this->m_Director = director;
            this->m_Duration = duration;
        }
        std::string GetTitle() const override
        {
            return this->m_Title;
        }

        void Display() override 
        { 
            std::cout << "ID: " << m_Id << "\nTitle: " << m_Title << "\nDirector: " << m_Director << "\nDuration: " << m_Duration << " minutes\nYear of Release: " << m_Year << "\n\n";
        }
};