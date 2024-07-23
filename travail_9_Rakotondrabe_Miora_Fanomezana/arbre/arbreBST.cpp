#include<iostream>
#include <cmath>
using namespace std;

template <typename Comparable>
class BinarySearchTree
{
    public:
    BinarySearchTree( ) {root=NULL;}//constructeur par defaut
    BinarySearchTree( const BinarySearchTree & rhs ) {*this=rhs;} // constructeur avec argument

    bool isEmpty( ) const {return (root==NULL);}//demande si l'arbre est vide
    
    void insert( const Comparable & x ) {insert(x,root,root);} //insere un element dans l'arbre
    bool contains( const Comparable & x ) const {return contains(x,root);}
    const BinarySearchTree & operator=( const BinarySearchTree & rhs )
    {
        if( this != &rhs )
        {
            //makeEmpty( );
            root = clone( rhs.root );
        }
        return *this;
    }

	friend ostream &operator<< (ostream& out, const BinarySearchTree& arbre)
	{
		BinaryNode* rootTemp = arbre.root;
        out << "TYPE\t" << "PARENT\t" << "NOEUD\t" << "HAUTEUR\t" << endl;
        out << "_____\t" << "_____\t" << "_____\t"<<"_____\t" << endl;
		arbre.imprimer(out, rootTemp,rootTemp);
		return out;
	}

    private:

    // Type de noeuds utilisés dans l'arbre
    struct BinaryNode
    {
       Comparable element; // ce sera notre element a comparer(notre prisme par exemple)
       int hauteur;
       BinaryNode *left;
       BinaryNode *right;

       BinaryNode( const Comparable & theElement, BinaryNode *lt, BinaryNode *rt )
         : element( theElement ), left( lt ), right( rt ) { }
    };

    // Pointeur vers la racine de l'arbre.
    BinaryNode *root;

/* 
	A FAIRE :	Imprimer dans le flux (out), tous les elements de l'arbre en ordre croissant!
*/
    void AffichageParentType(ostream& out, BinaryNode*& t, BinaryNode*& root)const {
        if (t == root) {
            out << "R\t" << t->element << "\t";
        }
        else {
            if (t->element < root->element) {//Gauche
                if (t == root->left)
                    out << "G\t" << root->element << "\t";
                else
                    AffichageParentType(out, t, root->left);
            }
            else {//Droite
                if (t == root->right)
                    out << "D\t" << root->element << "\t";
                else
                    AffichageParentType(out, t, root->right);
            }
        }
    }
	void imprimer(ostream& out, BinaryNode * & t,BinaryNode* Parent) const // methode prefixe
	{
        AffichageParentType(out, t, Parent);
        out << t->element<<"\t"<< t->hauteur << endl;//Affiche l'element;
        if (t->left != NULL)
            imprimer(out, t->left, Parent);
        if (t->right != NULL)
            imprimer(out, t->right,Parent);
            
	}
    void imprimer2(ostream& out, BinaryNode*& t,BinaryNode* &Parent)const // methode postfixe
    {
        if (t->left != NULL)
            imprimer2(out, t->left, Parent);
        if (t->right != NULL)
            imprimer2(out, t->right ,Parent);
        AffichageParentType(out, t,Parent);
        out << t->element << "\t" << t->hauteur << endl;//Affiche l'element;
    }
    //Calcul l'hauteur d'un noeud
    int hauteur(BinaryNode* &t)const {
        int HauteurGauche;
        int HauteurDroite;
        if (t == NULL)//feuille
            return -1;
        if (t->left == NULL) 
            HauteurGauche = 0;
        else 
            HauteurGauche = 1 + hauteur(t->left);
        if (t->right == NULL) 
            HauteurDroite = 0;
        else 
            HauteurDroite = 1 + hauteur(t->right);

        if (HauteurGauche >= HauteurDroite)
            return HauteurGauche;
        else
            return HauteurDroite;
    }
    //Mets a jour toute l'hauteur de l'arbre
    void MajHauteur(BinaryNode* &t)const {
        t->hauteur = hauteur(t);
        if (t->left != NULL)
            MajHauteur(t->left);
        if (t->right != NULL)
            MajHauteur(t->right);
    }
    //Rotation simple avec enfant gauche
    void rotationSimpleGauche(BinaryNode*& t, BinaryNode *& Parent)const {
        BinaryNode* Intermediaire;
        if (t == Parent) {//racinde de l'arbre
            Intermediaire = t;
            t = t->left;//k2 devient nouveau parent
            Intermediaire->left = t->right;//enfant droite de k1 devient enfant gauche de k2
            t->right = Intermediaire;//k1 adopte k2
        }
        else {//pas la racine
            Intermediaire = t;
            if (Parent->left == t) {
                Parent->left = t->left;
                Intermediaire->left = Parent->left->right;
                Parent->left->right = Intermediaire;
            }
            if (Parent->right == t) {
                Parent->right = t->left;
                Intermediaire->left = Parent->right->right;
                Parent->right->right = Intermediaire;
            }
        }
        Intermediaire = NULL;
    }
    //Rotation simple avec enfant droite
    void rotationSimpleDroite(BinaryNode*& t, BinaryNode*& Parent)const {
        BinaryNode* Intermediaire;
        if (t == Parent) {//racine de l'arbre
            Intermediaire = t;
            t = t->right;
            Intermediaire->right = t->left;;
            t->left = Intermediaire;
        }
        else {//pas la racine
            if (Parent->right == t) {
                Intermediaire = t;
                Parent->right = t->right;
                Intermediaire->right = Parent->right->left;
                Parent->right->left = Intermediaire;
            }
            if (Parent->left == t) {
                Intermediaire = t;
                Parent->left = t->right;
                Intermediaire->right = Parent->left->left;
                Parent->left->left = Intermediaire;
            }
        }
        Intermediaire = NULL;
    }
    //Rotation double avec enfant droite
    void rotationDoubleGauche(BinaryNode*& t, BinaryNode*& Parent)const {
        BinaryNode* Intermediaire;
        if (t == Parent) {
            Intermediaire = t;
            t = t->left->right;//K2 devient la racine
            Intermediaire->left->right = t->left;//enfant gauche de k2 devient enfant droite de k1
            t->left = Intermediaire->left;//k1 deveint enfant gauche de k2
            Intermediaire->left = t->right;//enfant droite de k2 devient enfant gauche de k3
            t->right = Intermediaire;//k3 devient enfant droite de k2
        }
        else {
            if (Parent->left == t) {
                Intermediaire = t;
                Parent->left = t->left->right;
                Intermediaire->left->right = Parent->left->left;
                Parent->left->left = Intermediaire->left;
                Intermediaire->left = Parent->left->right;
                Parent->left->right = Intermediaire;
            }
            if (Parent->right == t) {
                Intermediaire = t;
                Parent->right = t->left->right;
                Intermediaire->left->right = Parent->right->left;
                Parent->right->left = Intermediaire->left;
                Intermediaire->left = Parent->right->right;
                Parent->right->right = Intermediaire;
            }
        }
        Intermediaire = NULL;
    }
    //Rotation double avec enfant gauche
    void rotationDoubleDroite(BinaryNode*& t, BinaryNode*& Parent)const {
        BinaryNode* Intermediaire;
        if (t == Parent) {
            Intermediaire = t;
            t = t->right->left;//K2 devient la racine
            Intermediaire->right->left = t->right;//enfant droite de k2 devient enfant gauche de k1
            t->right = Intermediaire->right;//k1 devient enfant droite de k2
            Intermediaire->right = t->left;//enfant gauche de k2 devient enfant droite de k3(ancient racine)
            t->left = Intermediaire;//k3 devient enfant gauche de k2
        }
        else {
            if (Parent->right == t) {
                Intermediaire = t;
                Parent->right = t->right->left;
                Intermediaire->right->left = Parent->right->right;
                Parent->right->right = Intermediaire->right;
                Intermediaire->right = Parent->right->left;
                Parent->right->left = Intermediaire;
            }
            if (Parent->left == t) {
                Intermediaire = t;
                Parent->left = t->right->left;
                Intermediaire->right->left = Parent->left->right;
                Parent->left->right = Intermediaire->right;
                Intermediaire->right = Parent->left->left;
                Parent->left->left = Intermediaire;
            }
        }
        Intermediaire = NULL;
    }
    //Cheche le parent d'un noeud
    BinaryNode* ChercheParent(BinaryNode* &t, BinaryNode * &root) const {
        if (t == root) {
            return t;
        }
        else {
            if (t->element < root->element) {//Gauche
                if (t == root->left)
                    return root;
                else
                    return ChercheParent(t, root->left);
            }
            else {//Droite
                if (t == root->right)
                    return root;
                else
                    return ChercheParent(t, root->right);
            }
        }
    }
    // Insére un élément x dans le sous arbre t
    void insert( const Comparable & x, BinaryNode * &t, BinaryNode * &Parent)
    {
        if (t == NULL) {
            t = new BinaryNode(x, NULL, NULL);
        }
        else if (x < t->element) {//Insertion a gauche
            insert(x, t->left, Parent);
        }
        else if (t->element < x) {//Insertion a droite
            insert(x, t->right, Parent);
        }
        else
            ;  // x est déjà dans l'arbre; on ne fait rien
        t->hauteur = hauteur(t);
        if (hauteur(t->left) - hauteur(t->right) == 2) {//Insertion a gauche

            BinaryNode* MonParent = ChercheParent(t, Parent);
            if (x < t->left->element) // #CAS 1
                rotationSimpleGauche(t, MonParent);
            else // #CAS 2
                rotationDoubleGauche(t, MonParent);
            MajHauteur(Parent);
        }
        if (hauteur(t->right) - hauteur(t->left) == 2) {//Insertion a droite

            BinaryNode* MonParent = ChercheParent(t, Parent);
            if (x > t->right->element)//#CAS 3
                rotationSimpleDroite(t, MonParent);
            else//#CAS 4
                rotationDoubleDroite(t, MonParent);
            MajHauteur(Parent);
        }
    }



    // Cherche x dans le sous-arbre  t
    bool contains( const Comparable & x, BinaryNode *t ) const
    {
        if (t == NULL) {
            return false;
        }
        if (x < t->element) {
            return (contains(x, t->left));
        }
        else if (x > t->element) {
            return (contains(x,t->right));
        }
        else {
            return true;
        }
    }

    // Retourne une copie du sous-arbre t
    BinaryNode * clone( BinaryNode *t ) const
    {
        if( t == NULL )
            return NULL;
        return new BinaryNode( t->element, clone( t->left ), clone( t->right ) );
    }
};
