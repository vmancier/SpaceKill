#ifndef SCORE_HPP_INCLUDED
#define SCORE_HPP_INCLUDED

class Score
{

private:
    int m_score;
public:
    Score();    //constructeur par défaut

    ~Score();   //destructeur
    void scoreCalculation();
};

#endif // SCORE_HPP_INCLUDED
