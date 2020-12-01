#include "Headers/customerList.h"

using namespace std;

bool CustomerList::isValidPos(CustomerNode * c)
{
    CustomerNode* aux(customerNode);
    while (aux != nullptr) {
        if(aux == c)
            return true;
        aux = aux->getNextCustomer();
    }
    return false;
}

CustomerList::CustomerList() : customerNode(nullptr) {}

CustomerList::~CustomerList()
{
    deleteAll();
}

bool CustomerList::isEmpty()
{
    return customerNode == nullptr;
}


CustomerNode* CustomerList::getAnchor()
{
    return this->customerNode;
}

void CustomerList::insertCustomer(CustomerNode * p, const Customer & c)
{
    if(p != nullptr and !isValidPos(p)){
        errorMsg.setText("Error al insertar cliente");
        errorMsg.exec();
        return;
    }
    CustomerNode* aux(new CustomerNode(c));
    if(aux == nullptr){
        errorMsg.setText("Error al insertar cliente");
        errorMsg.exec();
        return;
    }
    if(p == nullptr){
        aux->setCustomerNode(this->customerNode);
        this->customerNode = aux;
    }
    else{
        aux->setCustomerNode(p->getNextCustomer());
        p->setCustomerNode(aux);
    }
}


void CustomerList::insertOrdered(const Customer & c)
{
    CustomerNode* aux(customerNode);
    CustomerNode* p(nullptr);

    while(aux != nullptr and c > aux->getCustomer())
    {
        p = aux;
        aux = aux->getNextCustomer();
    }
    insertCustomer(p, c);
}

CustomerNode* CustomerList::getPrevCustomer(CustomerNode * c)
{
    if(c == this->customerNode || !isValidPos(c))
        return nullptr;

    CustomerNode* aux(this->customerNode);

    while(aux->getNextCustomer() != c)
        aux = aux->getNextCustomer();

    return aux;
}

QJsonArray CustomerList::listToJson()
{
    QJsonArray customersJson;
    CustomerNode* aux(customerNode);
    while (aux != nullptr) {
        //Objeto para almacenar datos de clientes
        QJsonObject customerData;
        Customer c = aux->getCustomer();
        customerData["customerName"] = QString::fromStdString(c.getName());
        customerData["customerDate"] = QString::fromStdString(c.getDate().getAsString());
        customerData["customerDuration"] = QString::fromStdString(c.getDuration().getAsString());
        //Se agrega el cliente al arreglo
        customersJson.append(customerData);
        //se itera la lista
        aux = aux->getNextCustomer();
    }
    return customersJson;
}

void CustomerList::jsonToList(const QJsonArray jsonArray)
{
    //Se itera a traves del documento
    foreach (const QJsonValue & value, jsonArray) {
        QJsonObject obj = value.toObject();
        Customer newCustomer;
        newCustomer.setName(obj["customerName"].toString().toStdString());
        newCustomer.setDate(Date(obj["customerDate"].toString().toStdString()));
        newCustomer.setDuration(Duration(obj["customerDuration"].toString().toStdString()));
        //solo inserta al cliente si no existe ya
        if(this->getCustomerNode(newCustomer) == nullptr)
            insertOrdered(newCustomer);
    }
}

void CustomerList::exportList(const string & fileName)
{
    QFile file;
    file.setFileName(QString::fromStdString(fileName));
    if(!file.open(QIODevice::WriteOnly)){
        errorMsg.setText(QString::fromStdString("Error al guardar "+ fileName+ "!"));
        errorMsg.exec();
        return;
    }
    //Arreglo para almacenar a todos los clientes
    //se llena por medio de la funcion que regresa la lista en un arreglo de json
    QJsonArray customersJson = listToJson();
    //se lee el objeto en un byteArray
    QByteArray byteArray;
    byteArray = QJsonDocument(customersJson).toJson();
    //Se guarda en el archivo
    file.write(byteArray);
    file.close();
    errorMsg.setText(QString::fromStdString("Exportado con exito en: " + fileName));
    errorMsg.exec();
}

void CustomerList::importList(const string & fileName)
{
    QFile file(QString::fromStdString(fileName));

    if(!file.open(QIODevice::ReadOnly)){    //Si no se puede abre
        errorMsg.setText(QString::fromStdString("Error al abrir "+ fileName + "!"));
        errorMsg.exec();
        return;
    }

    QByteArray byteArray;
    byteArray = file.readAll(); //toma el contenido del json
    file.close();   //cierra el archivo

    QJsonParseError parseError;
    QJsonDocument jsonDoc;
    //crea un jsonDocument con el texto obtenido
    jsonDoc = QJsonDocument::fromJson(byteArray, &parseError);
    //Si existe algun error al leer el json
    if(parseError.error != QJsonParseError::NoError){
        errorMsg.setText(QString::fromStdString("Error al leer "+ fileName + "!"));
        errorMsg.exec();
        return;
    }
    //Pasa el documento a jsonArray para su manipulacion
    QJsonArray jsonArray;
    jsonArray = jsonDoc.array();
    jsonToList(jsonArray);
    errorMsg.setText("Importado con exito!");
    errorMsg.exec();
}

void CustomerList::removeCustomer(CustomerNode * c)
{
    if(!isValidPos(c)){
        errorMsg.setText("Error al eliminar");
        errorMsg.exec();
        return;
    }

    if(c == this->customerNode)
        this->customerNode = c->getNextCustomer();
    else
        this->getPrevCustomer(c)->setCustomerNode(c->getNextCustomer());

    delete c;
}

CustomerNode* CustomerList::getCustomerNode(const Customer& c)
{
    CustomerNode* aux(this->customerNode);

    while(aux != nullptr && aux->getCustomer() != c)
        aux = aux->getNextCustomer();

    return aux;
}

void CustomerList::deleteAll()
{
    CustomerNode* aux(this->customerNode);

    while(aux != nullptr){
        this->removeCustomer(aux);
        aux = aux->getNextCustomer();
    }
}

CustomerList& CustomerList::operator=(const CustomerList& c)
{
    this->deleteAll();
    this->customerNode = c.customerNode;
    return *this;
}
