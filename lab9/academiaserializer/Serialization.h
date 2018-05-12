//
// Created by owsikami on 09.05.18.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include <ostream>
#include <vector>
#include <functional>

namespace academia {

    // ------** SERIALIZERS **-------

    class Serializer; //nie mozesz uzyc jako wartosci i nie mozesz dziedziczyc

    class Serializable{
    public:
        virtual void Serialize (Serializer * c) const =0;
    };

    class Serializer{
    public:
        Serializer(std::ostream *out) :out_(*out) {}
        virtual  void IntegerField(const std::string &field_name, int value) =0;

        virtual void DoubleField(const std::string &field_name, double value) =0;

        virtual void StringField(const std::string &field_name, const std::string &value)=0;
        virtual void BooleanField(const std::string &field_name, bool value) =0;
        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value)=0;
        virtual void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value) =0;
        virtual void Header(const std::string &object_name) =0;
        virtual void Footer(const std::string &object_name) =0;

    protected:
        std::ostream & out_;
    };

    class JsonSerializer: public Serializer{
    public:

        JsonSerializer(std::ostream *out) :Serializer(out) {}

        void IntegerField(const std::string &field_name, int value) override;

        void DoubleField(const std::string &field_name, double value) override;

        void StringField(const std::string &field_name, const std::string &value) override;

        void BooleanField(const std::string &field_name, bool value) override;

        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;

        void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override;

        void Header(const std::string &object_name) override;

        void Footer(const std::string &object_name) override;

        void EnterComma(){
            if(is_first_){
                is_first_= false;
            } else {
                out_<<", ";
            }
        }

    private:
        bool is_first_=true;
        
    };


    class XmlSerializer: public Serializer{
    public:
        XmlSerializer(std::ostream *out) :Serializer(out) {}

        void IntegerField(const std::string &field_name, int value) override;

        void DoubleField(const std::string &field_name, double value) override;

        void StringField(const std::string &field_name, const std::string &value) override;

        void BooleanField(const std::string &field_name, bool value) override;

        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;

        void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override;

        void Header(const std::string &object_name) override;

        void Footer(const std::string &object_name) override;

    };



    // -------** SERIALIZABLE TYPES **--------


    class Room: public Serializable{
    public:
        enum class Type {
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASSROOM
        };

        Room(int id, std::string name, Type type ): id_(id), name_(name), type_(type){}
        void Serialize(Serializer *c) const override;
        std::string EnumToString(Type enumerator) const;

    private:
        int id_;
        std::string name_;
        Type type_;
    };

    class Building: public Serializable {
    public:


        Building(int id, const std::string &name, const std::vector<std::reference_wrapper<const academia::Serializable>> &rooms ):id_(id), name_(name), rooms_(rooms){}
        void Serialize(Serializer *c) const override;

    private:
        int id_;
        std::string name_;
        std::vector<std::reference_wrapper<const academia::Serializable>> rooms_;
    };










}


#endif //JIMP_EXERCISES_SERIALIZATION_H
