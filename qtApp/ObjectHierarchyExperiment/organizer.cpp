#include "organizer.h"
namespace machineSpace {

message::message(){
    p_task = nullptr;
    p_data_0 = nullptr;
    p_data_1 = nullptr;
}

message::message(TaskMap task){
    p_task = new TaskMap(task);
    p_data_0 = nullptr;
    p_data_1 = nullptr;
}

message::message(TaskMap task, float data){
    p_task = new TaskMap(task);
    p_data_0 = new float(data);
    p_data_1 = nullptr;
}

message::message(TaskMap task, float data0, float data1){
    p_task = new TaskMap(task);
    p_data_0 = new float(data0);
    p_data_1 = new float(data1);
}

message::~message()
{
    delete p_task;
    delete p_data_0;
    delete p_data_1;
}


TaskMap *message::task()
{
    if(p_task == nullptr)
        p_task = new TaskMap(a);
    return p_task;
}

float *message::data_0()
{
    if(p_data_0 == nullptr)
        p_data_0 = new float(0);
    return p_data_0;
}

float *message::data_1()
{
    if(p_data_1 == nullptr)
        p_data_1 = new float(0);
    return p_data_1;
}


void message::setTask(TaskMap task)
{
    if(p_task != nullptr)
        delete p_task;
    p_task = new TaskMap(task);
}

void message::setData_0(float data)
{
    if(p_data_0 != nullptr)
        delete p_data_0;
    p_data_0 = new float(data);
}

void message::setData_1(float data)
{
    if(p_data_1 != nullptr)
        delete p_data_1;
    p_data_1 = new float(data);
}



}
