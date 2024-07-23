#include<iostream>
using namespace std;

template <typename Comparable>
class BinarySearchTree
{
    public:
    BinarySearchTree( ) {root=NULL;}//constructeur par defaut
    BinarySearchTree( const BinarySearchTree & rhs ) {*this=rhs;} // constructeur avec argument
    ~BinarySearchTree( ) {makeEmpty();}//destructeur

    bool isEmpty( ) const {return (root==NULL);}//demande si l'arbre est vide
    void makeEmpty( ) {makeEmpty(root);}//vide l'arbre
    
    void insert( const Comparable & x ) {insert(x,root);} //insere un element dans l'arbre
    void remove( const Comparable & x ) {remove(x,root);}
    bool contains( const Comparable & x ) const {return contains(x,root);}
    
    const Comparable & findMin( ) const {return findMin(root)->element;}
    const Comparable & findMax( ) const {return findMax(root)->element;}

    const BinarySearchTree & operator=( const BinarySearchTree & rhs )
    {
        if( this != &rhs )
        {
            makeEmpty( );
            root = clone( rhs.root );
        }
        return *this;
    }

	friend ostream &operator<< (ostream& out, const BinarySearchTree& arbre)
	{
		BinaryNode* rootTemp = arbre.root;
		arbre.imprimer(out, rootTemp);
		return out;
	}

    private:

    // Type de noeuds utilisés dans l'arbre
    struct BinaryNode
    {
       Comparable element; // ce sera notre element a comparer(notre prisme par exemple)
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
	void imprimer(ostream& out, BinaryNode * & t) const
	{
        //out << t->element;//Affiche l'element;
        if (t->left != NULL) 
            imprimer(out, t->left);
        if (t->right != NULL)
            imprimer(out, t->right);
        out << t->element;//Affiche l'element;
	}


    // Insére un élément x dans le sous arbre t
    void insert( const Comparable & x, BinaryNode * &t )
    {
        if( t == NULL )
            t = new BinaryNode( x, NULL, NULL );
        else if( x < t->element )
            insert( x, t->left );
        else if( t->element < x )
            insert( x, t->right );
        else
            ;  // x est déjà dans l'arbre; on ne fait rien
    }

    // Enleve un élément x dans le sous-arbre t
    void remove(const Comparable & x, BinaryNode * & t )
    {
        if( t == NULL )
            return;   // x n'est pas dans l'arbre; on ne fait rien
        if (x < t->element) {
           remove(x, t->left);
        }
        else 
             if( t->element < x )
                 remove( x, t->right );
             else 
                  if( t->left != NULL && t->right != NULL ) // Deux enfants
                  {
                      t->element = findMin( t->right )->element;
                      remove( t->element, t->right );
                  }
                  else    // Au plus un enfant
                  {
                       BinaryNode *oldNode = t;
                       t = ( t->left != NULL ) ? t->left : t->right;
                       delete oldNode;
                  }
    }


    // Trouve le plus petit élément dans le sous-arbre  t
    // (méthode récursive)
    BinaryNode * findMin( BinaryNode *t ) const
    {
        if (t == NULL)
            return NULL;//l'arbre est vide
        else
            if (t->left == NULL)
                return(t);
            else
                return(findMin(t->left));
    }

    // Trouve le plus grand élément dans le sous-arbre  t
    // (méthode itérative)
    BinaryNode * findMax( BinaryNode *t ) const
    {
        if (t == NULL)
            return NULL;//arbre vide
        else
            if (t->right == NULL)
                return t;
            else
                return findMax(t->right);
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

    // Élimine le sous-arbre t
    void makeEmpty( BinaryNode * & t )
    {
        if( t != NULL )
        {
            makeEmpty( t->left );
            makeEmpty( t->right );
            delete t;
        }
        t = NULL;
    }

    // Retourne une copie du sous-arbre t
    BinaryNode * clone( BinaryNode *t ) const
    {
        if( t == NULL )
            return NULL;
        return new BinaryNode( t->element, clone( t->left ), clone( t->right ) );
    }
};
