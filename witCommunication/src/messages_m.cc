//
// Generated file, do not edit! Created by opp_msgc 4.2 from messages.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "messages_m.h"

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




Register_Class(myPosition);

myPosition::myPosition(const char *name, int kind) : cMessage(name,kind)
{
    this->srcNodeID_var = 0;
    this->destinationNodeID_var = 0;
    this->nodeID_var = 0;
    this->x_var = 0;
    this->y_var = 0;
}

myPosition::myPosition(const myPosition& other) : cMessage(other)
{
    copy(other);
}

myPosition::~myPosition()
{
}

myPosition& myPosition::operator=(const myPosition& other)
{
    if (this==&other) return *this;
    cMessage::operator=(other);
    copy(other);
    return *this;
}

void myPosition::copy(const myPosition& other)
{
    this->srcNodeID_var = other.srcNodeID_var;
    this->destinationNodeID_var = other.destinationNodeID_var;
    this->nodeID_var = other.nodeID_var;
    this->x_var = other.x_var;
    this->y_var = other.y_var;
}

void myPosition::parsimPack(cCommBuffer *b)
{
    cMessage::parsimPack(b);
    doPacking(b,this->srcNodeID_var);
    doPacking(b,this->destinationNodeID_var);
    doPacking(b,this->nodeID_var);
    doPacking(b,this->x_var);
    doPacking(b,this->y_var);
}

void myPosition::parsimUnpack(cCommBuffer *b)
{
    cMessage::parsimUnpack(b);
    doUnpacking(b,this->srcNodeID_var);
    doUnpacking(b,this->destinationNodeID_var);
    doUnpacking(b,this->nodeID_var);
    doUnpacking(b,this->x_var);
    doUnpacking(b,this->y_var);
}

int myPosition::getSrcNodeID() const
{
    return srcNodeID_var;
}

void myPosition::setSrcNodeID(int srcNodeID)
{
    this->srcNodeID_var = srcNodeID;
}

int myPosition::getDestinationNodeID() const
{
    return destinationNodeID_var;
}

void myPosition::setDestinationNodeID(int destinationNodeID)
{
    this->destinationNodeID_var = destinationNodeID;
}

int myPosition::getNodeID() const
{
    return nodeID_var;
}

void myPosition::setNodeID(int nodeID)
{
    this->nodeID_var = nodeID;
}

int myPosition::getX() const
{
    return x_var;
}

void myPosition::setX(int x)
{
    this->x_var = x;
}

int myPosition::getY() const
{
    return y_var;
}

void myPosition::setY(int y)
{
    this->y_var = y;
}

class myPositionDescriptor : public cClassDescriptor
{
  public:
    myPositionDescriptor();
    virtual ~myPositionDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(myPositionDescriptor);

myPositionDescriptor::myPositionDescriptor() : cClassDescriptor("myPosition", "cMessage")
{
}

myPositionDescriptor::~myPositionDescriptor()
{
}

bool myPositionDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<myPosition *>(obj)!=NULL;
}

const char *myPositionDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int myPositionDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount(object) : 5;
}

unsigned int myPositionDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *myPositionDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "srcNodeID",
        "destinationNodeID",
        "nodeID",
        "x",
        "y",
    };
    return (field>=0 && field<5) ? fieldNames[field] : NULL;
}

int myPositionDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcNodeID")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationNodeID")==0) return base+1;
    if (fieldName[0]=='n' && strcmp(fieldName, "nodeID")==0) return base+2;
    if (fieldName[0]=='x' && strcmp(fieldName, "x")==0) return base+3;
    if (fieldName[0]=='y' && strcmp(fieldName, "y")==0) return base+4;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *myPositionDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : NULL;
}

const char *myPositionDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int myPositionDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    myPosition *pp = (myPosition *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string myPositionDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    myPosition *pp = (myPosition *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getSrcNodeID());
        case 1: return long2string(pp->getDestinationNodeID());
        case 2: return long2string(pp->getNodeID());
        case 3: return long2string(pp->getX());
        case 4: return long2string(pp->getY());
        default: return "";
    }
}

bool myPositionDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    myPosition *pp = (myPosition *)object; (void)pp;
    switch (field) {
        case 0: pp->setSrcNodeID(string2long(value)); return true;
        case 1: pp->setDestinationNodeID(string2long(value)); return true;
        case 2: pp->setNodeID(string2long(value)); return true;
        case 3: pp->setX(string2long(value)); return true;
        case 4: pp->setY(string2long(value)); return true;
        default: return false;
    }
}

const char *myPositionDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<5) ? fieldStructNames[field] : NULL;
}

void *myPositionDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    myPosition *pp = (myPosition *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(ImYourMaster);

ImYourMaster::ImYourMaster(const char *name, int kind) : cMessage(name,kind)
{
    this->srcNodeID_var = 0;
    this->destinationNodeID_var = 0;
}

ImYourMaster::ImYourMaster(const ImYourMaster& other) : cMessage(other)
{
    copy(other);
}

ImYourMaster::~ImYourMaster()
{
}

ImYourMaster& ImYourMaster::operator=(const ImYourMaster& other)
{
    if (this==&other) return *this;
    cMessage::operator=(other);
    copy(other);
    return *this;
}

void ImYourMaster::copy(const ImYourMaster& other)
{
    this->srcNodeID_var = other.srcNodeID_var;
    this->destinationNodeID_var = other.destinationNodeID_var;
}

void ImYourMaster::parsimPack(cCommBuffer *b)
{
    cMessage::parsimPack(b);
    doPacking(b,this->srcNodeID_var);
    doPacking(b,this->destinationNodeID_var);
}

void ImYourMaster::parsimUnpack(cCommBuffer *b)
{
    cMessage::parsimUnpack(b);
    doUnpacking(b,this->srcNodeID_var);
    doUnpacking(b,this->destinationNodeID_var);
}

int ImYourMaster::getSrcNodeID() const
{
    return srcNodeID_var;
}

void ImYourMaster::setSrcNodeID(int srcNodeID)
{
    this->srcNodeID_var = srcNodeID;
}

int ImYourMaster::getDestinationNodeID() const
{
    return destinationNodeID_var;
}

void ImYourMaster::setDestinationNodeID(int destinationNodeID)
{
    this->destinationNodeID_var = destinationNodeID;
}

class ImYourMasterDescriptor : public cClassDescriptor
{
  public:
    ImYourMasterDescriptor();
    virtual ~ImYourMasterDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(ImYourMasterDescriptor);

ImYourMasterDescriptor::ImYourMasterDescriptor() : cClassDescriptor("ImYourMaster", "cMessage")
{
}

ImYourMasterDescriptor::~ImYourMasterDescriptor()
{
}

bool ImYourMasterDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<ImYourMaster *>(obj)!=NULL;
}

const char *ImYourMasterDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int ImYourMasterDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int ImYourMasterDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *ImYourMasterDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "srcNodeID",
        "destinationNodeID",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int ImYourMasterDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcNodeID")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationNodeID")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *ImYourMasterDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *ImYourMasterDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int ImYourMasterDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    ImYourMaster *pp = (ImYourMaster *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string ImYourMasterDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    ImYourMaster *pp = (ImYourMaster *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getSrcNodeID());
        case 1: return long2string(pp->getDestinationNodeID());
        default: return "";
    }
}

bool ImYourMasterDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    ImYourMaster *pp = (ImYourMaster *)object; (void)pp;
    switch (field) {
        case 0: pp->setSrcNodeID(string2long(value)); return true;
        case 1: pp->setDestinationNodeID(string2long(value)); return true;
        default: return false;
    }
}

const char *ImYourMasterDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
    };
    return (field>=0 && field<2) ? fieldStructNames[field] : NULL;
}

void *ImYourMasterDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    ImYourMaster *pp = (ImYourMaster *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(ImYourSlave);

ImYourSlave::ImYourSlave(const char *name, int kind) : cMessage(name,kind)
{
    this->srcNodeID_var = 0;
    this->destinationNodeID_var = 0;
}

ImYourSlave::ImYourSlave(const ImYourSlave& other) : cMessage(other)
{
    copy(other);
}

ImYourSlave::~ImYourSlave()
{
}

ImYourSlave& ImYourSlave::operator=(const ImYourSlave& other)
{
    if (this==&other) return *this;
    cMessage::operator=(other);
    copy(other);
    return *this;
}

void ImYourSlave::copy(const ImYourSlave& other)
{
    this->srcNodeID_var = other.srcNodeID_var;
    this->destinationNodeID_var = other.destinationNodeID_var;
}

void ImYourSlave::parsimPack(cCommBuffer *b)
{
    cMessage::parsimPack(b);
    doPacking(b,this->srcNodeID_var);
    doPacking(b,this->destinationNodeID_var);
}

void ImYourSlave::parsimUnpack(cCommBuffer *b)
{
    cMessage::parsimUnpack(b);
    doUnpacking(b,this->srcNodeID_var);
    doUnpacking(b,this->destinationNodeID_var);
}

int ImYourSlave::getSrcNodeID() const
{
    return srcNodeID_var;
}

void ImYourSlave::setSrcNodeID(int srcNodeID)
{
    this->srcNodeID_var = srcNodeID;
}

int ImYourSlave::getDestinationNodeID() const
{
    return destinationNodeID_var;
}

void ImYourSlave::setDestinationNodeID(int destinationNodeID)
{
    this->destinationNodeID_var = destinationNodeID;
}

class ImYourSlaveDescriptor : public cClassDescriptor
{
  public:
    ImYourSlaveDescriptor();
    virtual ~ImYourSlaveDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(ImYourSlaveDescriptor);

ImYourSlaveDescriptor::ImYourSlaveDescriptor() : cClassDescriptor("ImYourSlave", "cMessage")
{
}

ImYourSlaveDescriptor::~ImYourSlaveDescriptor()
{
}

bool ImYourSlaveDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<ImYourSlave *>(obj)!=NULL;
}

const char *ImYourSlaveDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int ImYourSlaveDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int ImYourSlaveDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *ImYourSlaveDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "srcNodeID",
        "destinationNodeID",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int ImYourSlaveDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcNodeID")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationNodeID")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *ImYourSlaveDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *ImYourSlaveDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int ImYourSlaveDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    ImYourSlave *pp = (ImYourSlave *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string ImYourSlaveDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    ImYourSlave *pp = (ImYourSlave *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getSrcNodeID());
        case 1: return long2string(pp->getDestinationNodeID());
        default: return "";
    }
}

bool ImYourSlaveDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    ImYourSlave *pp = (ImYourSlave *)object; (void)pp;
    switch (field) {
        case 0: pp->setSrcNodeID(string2long(value)); return true;
        case 1: pp->setDestinationNodeID(string2long(value)); return true;
        default: return false;
    }
}

const char *ImYourSlaveDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
    };
    return (field>=0 && field<2) ? fieldStructNames[field] : NULL;
}

void *ImYourSlaveDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    ImYourSlave *pp = (ImYourSlave *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(SyncMsg);

SyncMsg::SyncMsg(const char *name, int kind) : cMessage(name,kind)
{
    this->srcNodeID_var = 0;
    this->destinationNodeID_var = 0;
}

SyncMsg::SyncMsg(const SyncMsg& other) : cMessage(other)
{
    copy(other);
}

SyncMsg::~SyncMsg()
{
}

SyncMsg& SyncMsg::operator=(const SyncMsg& other)
{
    if (this==&other) return *this;
    cMessage::operator=(other);
    copy(other);
    return *this;
}

void SyncMsg::copy(const SyncMsg& other)
{
    this->srcNodeID_var = other.srcNodeID_var;
    this->destinationNodeID_var = other.destinationNodeID_var;
}

void SyncMsg::parsimPack(cCommBuffer *b)
{
    cMessage::parsimPack(b);
    doPacking(b,this->srcNodeID_var);
    doPacking(b,this->destinationNodeID_var);
}

void SyncMsg::parsimUnpack(cCommBuffer *b)
{
    cMessage::parsimUnpack(b);
    doUnpacking(b,this->srcNodeID_var);
    doUnpacking(b,this->destinationNodeID_var);
}

int SyncMsg::getSrcNodeID() const
{
    return srcNodeID_var;
}

void SyncMsg::setSrcNodeID(int srcNodeID)
{
    this->srcNodeID_var = srcNodeID;
}

int SyncMsg::getDestinationNodeID() const
{
    return destinationNodeID_var;
}

void SyncMsg::setDestinationNodeID(int destinationNodeID)
{
    this->destinationNodeID_var = destinationNodeID;
}

class SyncMsgDescriptor : public cClassDescriptor
{
  public:
    SyncMsgDescriptor();
    virtual ~SyncMsgDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(SyncMsgDescriptor);

SyncMsgDescriptor::SyncMsgDescriptor() : cClassDescriptor("SyncMsg", "cMessage")
{
}

SyncMsgDescriptor::~SyncMsgDescriptor()
{
}

bool SyncMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<SyncMsg *>(obj)!=NULL;
}

const char *SyncMsgDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int SyncMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int SyncMsgDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *SyncMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "srcNodeID",
        "destinationNodeID",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int SyncMsgDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcNodeID")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationNodeID")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *SyncMsgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *SyncMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int SyncMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    SyncMsg *pp = (SyncMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string SyncMsgDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    SyncMsg *pp = (SyncMsg *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getSrcNodeID());
        case 1: return long2string(pp->getDestinationNodeID());
        default: return "";
    }
}

bool SyncMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    SyncMsg *pp = (SyncMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setSrcNodeID(string2long(value)); return true;
        case 1: pp->setDestinationNodeID(string2long(value)); return true;
        default: return false;
    }
}

const char *SyncMsgDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
    };
    return (field>=0 && field<2) ? fieldStructNames[field] : NULL;
}

void *SyncMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    SyncMsg *pp = (SyncMsg *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(FollowUp);

FollowUp::FollowUp(const char *name, int kind) : cMessage(name,kind)
{
    this->srcNodeID_var = 0;
    this->timeMoment_var = 0;
    this->destinationNodeID_var = 0;
}

FollowUp::FollowUp(const FollowUp& other) : cMessage(other)
{
    copy(other);
}

FollowUp::~FollowUp()
{
}

FollowUp& FollowUp::operator=(const FollowUp& other)
{
    if (this==&other) return *this;
    cMessage::operator=(other);
    copy(other);
    return *this;
}

void FollowUp::copy(const FollowUp& other)
{
    this->srcNodeID_var = other.srcNodeID_var;
    this->timeMoment_var = other.timeMoment_var;
    this->destinationNodeID_var = other.destinationNodeID_var;
}

void FollowUp::parsimPack(cCommBuffer *b)
{
    cMessage::parsimPack(b);
    doPacking(b,this->srcNodeID_var);
    doPacking(b,this->timeMoment_var);
    doPacking(b,this->destinationNodeID_var);
}

void FollowUp::parsimUnpack(cCommBuffer *b)
{
    cMessage::parsimUnpack(b);
    doUnpacking(b,this->srcNodeID_var);
    doUnpacking(b,this->timeMoment_var);
    doUnpacking(b,this->destinationNodeID_var);
}

int FollowUp::getSrcNodeID() const
{
    return srcNodeID_var;
}

void FollowUp::setSrcNodeID(int srcNodeID)
{
    this->srcNodeID_var = srcNodeID;
}

simtime_t FollowUp::getTimeMoment() const
{
    return timeMoment_var;
}

void FollowUp::setTimeMoment(simtime_t timeMoment)
{
    this->timeMoment_var = timeMoment;
}

int FollowUp::getDestinationNodeID() const
{
    return destinationNodeID_var;
}

void FollowUp::setDestinationNodeID(int destinationNodeID)
{
    this->destinationNodeID_var = destinationNodeID;
}

class FollowUpDescriptor : public cClassDescriptor
{
  public:
    FollowUpDescriptor();
    virtual ~FollowUpDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(FollowUpDescriptor);

FollowUpDescriptor::FollowUpDescriptor() : cClassDescriptor("FollowUp", "cMessage")
{
}

FollowUpDescriptor::~FollowUpDescriptor()
{
}

bool FollowUpDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<FollowUp *>(obj)!=NULL;
}

const char *FollowUpDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int FollowUpDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int FollowUpDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *FollowUpDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "srcNodeID",
        "timeMoment",
        "destinationNodeID",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int FollowUpDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcNodeID")==0) return base+0;
    if (fieldName[0]=='t' && strcmp(fieldName, "timeMoment")==0) return base+1;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationNodeID")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *FollowUpDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "simtime_t",
        "int",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *FollowUpDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int FollowUpDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    FollowUp *pp = (FollowUp *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string FollowUpDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    FollowUp *pp = (FollowUp *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getSrcNodeID());
        case 1: return double2string(pp->getTimeMoment());
        case 2: return long2string(pp->getDestinationNodeID());
        default: return "";
    }
}

bool FollowUpDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    FollowUp *pp = (FollowUp *)object; (void)pp;
    switch (field) {
        case 0: pp->setSrcNodeID(string2long(value)); return true;
        case 1: pp->setTimeMoment(string2double(value)); return true;
        case 2: pp->setDestinationNodeID(string2long(value)); return true;
        default: return false;
    }
}

const char *FollowUpDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<3) ? fieldStructNames[field] : NULL;
}

void *FollowUpDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    FollowUp *pp = (FollowUp *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(DelayReq);

DelayReq::DelayReq(const char *name, int kind) : cMessage(name,kind)
{
    this->srcNodeID_var = 0;
    this->destinationNodeID_var = 0;
}

DelayReq::DelayReq(const DelayReq& other) : cMessage(other)
{
    copy(other);
}

DelayReq::~DelayReq()
{
}

DelayReq& DelayReq::operator=(const DelayReq& other)
{
    if (this==&other) return *this;
    cMessage::operator=(other);
    copy(other);
    return *this;
}

void DelayReq::copy(const DelayReq& other)
{
    this->srcNodeID_var = other.srcNodeID_var;
    this->destinationNodeID_var = other.destinationNodeID_var;
}

void DelayReq::parsimPack(cCommBuffer *b)
{
    cMessage::parsimPack(b);
    doPacking(b,this->srcNodeID_var);
    doPacking(b,this->destinationNodeID_var);
}

void DelayReq::parsimUnpack(cCommBuffer *b)
{
    cMessage::parsimUnpack(b);
    doUnpacking(b,this->srcNodeID_var);
    doUnpacking(b,this->destinationNodeID_var);
}

int DelayReq::getSrcNodeID() const
{
    return srcNodeID_var;
}

void DelayReq::setSrcNodeID(int srcNodeID)
{
    this->srcNodeID_var = srcNodeID;
}

int DelayReq::getDestinationNodeID() const
{
    return destinationNodeID_var;
}

void DelayReq::setDestinationNodeID(int destinationNodeID)
{
    this->destinationNodeID_var = destinationNodeID;
}

class DelayReqDescriptor : public cClassDescriptor
{
  public:
    DelayReqDescriptor();
    virtual ~DelayReqDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(DelayReqDescriptor);

DelayReqDescriptor::DelayReqDescriptor() : cClassDescriptor("DelayReq", "cMessage")
{
}

DelayReqDescriptor::~DelayReqDescriptor()
{
}

bool DelayReqDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<DelayReq *>(obj)!=NULL;
}

const char *DelayReqDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int DelayReqDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int DelayReqDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *DelayReqDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "srcNodeID",
        "destinationNodeID",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int DelayReqDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcNodeID")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationNodeID")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *DelayReqDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *DelayReqDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int DelayReqDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    DelayReq *pp = (DelayReq *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string DelayReqDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    DelayReq *pp = (DelayReq *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getSrcNodeID());
        case 1: return long2string(pp->getDestinationNodeID());
        default: return "";
    }
}

bool DelayReqDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    DelayReq *pp = (DelayReq *)object; (void)pp;
    switch (field) {
        case 0: pp->setSrcNodeID(string2long(value)); return true;
        case 1: pp->setDestinationNodeID(string2long(value)); return true;
        default: return false;
    }
}

const char *DelayReqDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
    };
    return (field>=0 && field<2) ? fieldStructNames[field] : NULL;
}

void *DelayReqDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    DelayReq *pp = (DelayReq *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(DelayResp);

DelayResp::DelayResp(const char *name, int kind) : cMessage(name,kind)
{
    this->srcNodeID_var = 0;
    this->destinationNodeID_var = 0;
    this->timeMoment_var = 0;
}

DelayResp::DelayResp(const DelayResp& other) : cMessage(other)
{
    copy(other);
}

DelayResp::~DelayResp()
{
}

DelayResp& DelayResp::operator=(const DelayResp& other)
{
    if (this==&other) return *this;
    cMessage::operator=(other);
    copy(other);
    return *this;
}

void DelayResp::copy(const DelayResp& other)
{
    this->srcNodeID_var = other.srcNodeID_var;
    this->destinationNodeID_var = other.destinationNodeID_var;
    this->timeMoment_var = other.timeMoment_var;
}

void DelayResp::parsimPack(cCommBuffer *b)
{
    cMessage::parsimPack(b);
    doPacking(b,this->srcNodeID_var);
    doPacking(b,this->destinationNodeID_var);
    doPacking(b,this->timeMoment_var);
}

void DelayResp::parsimUnpack(cCommBuffer *b)
{
    cMessage::parsimUnpack(b);
    doUnpacking(b,this->srcNodeID_var);
    doUnpacking(b,this->destinationNodeID_var);
    doUnpacking(b,this->timeMoment_var);
}

int DelayResp::getSrcNodeID() const
{
    return srcNodeID_var;
}

void DelayResp::setSrcNodeID(int srcNodeID)
{
    this->srcNodeID_var = srcNodeID;
}

int DelayResp::getDestinationNodeID() const
{
    return destinationNodeID_var;
}

void DelayResp::setDestinationNodeID(int destinationNodeID)
{
    this->destinationNodeID_var = destinationNodeID;
}

simtime_t DelayResp::getTimeMoment() const
{
    return timeMoment_var;
}

void DelayResp::setTimeMoment(simtime_t timeMoment)
{
    this->timeMoment_var = timeMoment;
}

class DelayRespDescriptor : public cClassDescriptor
{
  public:
    DelayRespDescriptor();
    virtual ~DelayRespDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(DelayRespDescriptor);

DelayRespDescriptor::DelayRespDescriptor() : cClassDescriptor("DelayResp", "cMessage")
{
}

DelayRespDescriptor::~DelayRespDescriptor()
{
}

bool DelayRespDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<DelayResp *>(obj)!=NULL;
}

const char *DelayRespDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int DelayRespDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int DelayRespDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *DelayRespDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "srcNodeID",
        "destinationNodeID",
        "timeMoment",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int DelayRespDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcNodeID")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationNodeID")==0) return base+1;
    if (fieldName[0]=='t' && strcmp(fieldName, "timeMoment")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *DelayRespDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "simtime_t",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *DelayRespDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int DelayRespDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    DelayResp *pp = (DelayResp *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string DelayRespDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    DelayResp *pp = (DelayResp *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getSrcNodeID());
        case 1: return long2string(pp->getDestinationNodeID());
        case 2: return double2string(pp->getTimeMoment());
        default: return "";
    }
}

bool DelayRespDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    DelayResp *pp = (DelayResp *)object; (void)pp;
    switch (field) {
        case 0: pp->setSrcNodeID(string2long(value)); return true;
        case 1: pp->setDestinationNodeID(string2long(value)); return true;
        case 2: pp->setTimeMoment(string2double(value)); return true;
        default: return false;
    }
}

const char *DelayRespDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<3) ? fieldStructNames[field] : NULL;
}

void *DelayRespDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    DelayResp *pp = (DelayResp *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


