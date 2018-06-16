#ifndef ORGANIZER_H
#define ORGANIZER_H

namespace machineSpace {

enum TaskMap{a,b,c};

class message
{
public:
    message();
    message(TaskMap task);
    message(TaskMap task, float data);
    message(TaskMap task, float data0, float data1);
    ~message();

    TaskMap *task();
    float *data_0();
    float *data_1();

    void setTask(TaskMap task);
    void setData_0(float data);
    void setData_1(float data);



private:

    TaskMap * p_task;
    float * p_data_0;
    float * p_data_1;
};


#endif // ORGANIZER_H
}
