/*!
 * \file myVec.cpp
 * \brief Classe Vec : vecteur gérant les flottants en paramètre
 * \author Valentin LIEVIN
 * \version 15/1/2015
 */

#include "myVec.h"

using namespace std;
using namespace cv;

myVec::myVec()
{
    //ctor
}

myVec::myVec(double mx, double my) : x(mx), y(my)
{
    //ctor
}
myVec::~myVec()
{
    //dtor
}

void myVec::AfficherPoint(cv::Mat img)const
{
    AfficherPointcv(img, cv::Point(x,y));
}

void myVec::AfficherVecteur(cv::Mat image, myVec vorigine)const
{
    //AfficherVecteurcv(image, cv::Point(M_LONG_VECTOR*x,M_LONG_VECTOR*y), Point(origine.Getx(), origine.Gety()));

    Scalar bleu = Scalar(200, 35, 0); // définit la couleur d'un vecteur : bleu

     // on trace la ligne représentant le corps du vecteur
    Point origine = Point(vorigine.Getx(), vorigine.Gety());
    Point direction = Point(M_LONG_VECTOR * x, M_LONG_VECTOR * y);
    line(image, origine,origine+ direction, bleu ,M_THICKNESS,8);

     //on trace la tête du vecteur à l'aide d'un polygone plein

     Point directionOrtho(- direction.y ,direction.x );
     //taille de la tête de la flèche : longueur : L en pixel
     float L = 5;
     vector<Point> tete;
     tete.push_back(origine+direction);// on rentre l'extrêmité de la flèche
     tete.push_back( origine+direction - ((L/M_LONG_VECTOR) * direction) + (L/(4*M_LONG_VECTOR)) * directionOrtho);
     tete.push_back( tete[1] - (L/(2*M_LONG_VECTOR))* directionOrtho);

     AfficherPolygon(image, tete, bleu);
}


double myVec::GetNorme() const
{
return sqrt(x*x+y*y);
}

void myVec::operator*=(double const& alpha)
{
x*=alpha;
y*=alpha;
}

void myVec::Normalise()
{
    double norme = GetNorme();
    x*=(1/norme);
    y*=(1/norme);
}
