//
// Created by owsikami on 23.05.18.
//

#ifndef JIMP_EXERCISES_FACTORYMETHOD_H
#define JIMP_EXERCISES_FACTORYMETHOD_H


#include <vector>

namespace factoryMethod{
    template <class T>
    auto Value(const T& x){
        return *x;
    }

    template <class RepositoryMember>
    class Query{
    public:
        virtual bool Accept(RepositoryMember)=0;
        virtual ~Query()=default;//!!

    };
    template <class RepositoryMember>
    class Repository{
    public:
        Repository(RepositoryMember m){};


        int Size(){
            return repository_.size();

        }
        int NextId(){
            index++;
            return index;

        }
        std::vector<RepositoryMember> FindBy(Query<RepositoryMember> * q){ // podtyp query
            std::vector<RepositoryMember> x;
            for(auto v:repository_){
                if (q->Accept(v)){
                    x.push_back(v);
                }
            }
            return x;


        }
        RepositoryMember operator[](int i){
                return repository_[i];

        }
    private:
        std::vector <RepositoryMember> repository_;
        int index=1;



    };




}




#endif //JIMP_EXERCISES_FACTORYMETHOD_H
