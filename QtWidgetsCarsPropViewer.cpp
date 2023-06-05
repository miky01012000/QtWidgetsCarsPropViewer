#include "QtWidgetsCarsPropViewer.h"

QtWidgetsCarsPropViewer::QtWidgetsCarsPropViewer(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    QFrame* fr_AddCar = findChild<QFrame*>("frame_AddCar");
    fr_AddCar->setVisible(false);

    QFrame* fr_ShowCars = findChild<QFrame*>("frame_ShowCars");
    fr_ShowCars->setVisible(false);

    filter = filter_Zero;
}

QtWidgetsCarsPropViewer::~QtWidgetsCarsPropViewer()
{}

void QtWidgetsCarsPropViewer::Hide_Add_Show_Filter()
{
    QFrame* fr_ShowCars = findChild<QFrame*>("frame_ShowCars");
    fr_ShowCars->setVisible(true);

    QFrame* fr_AddCar = findChild<QFrame*>("frame_AddCar");
    fr_AddCar->setVisible(false);

    filter = filter_Zero;
}

void QtWidgetsCarsPropViewer::add_new_car()
{
    Car* tmp_car = new Car();

    QLineEdit* le_id = findChild<QLineEdit*>("lineEdit_id");
    QLineEdit* le_mark = findChild<QLineEdit*>("lineEdit_mark");
    QLineEdit* le_model = findChild<QLineEdit*>("lineEdit_model");
    QLineEdit* le_year = findChild<QLineEdit*>("lineEdit_year");
    QLineEdit* le_color = findChild<QLineEdit*>("lineEdit_color");
    QLineEdit* le_price = findChild<QLineEdit*>("lineEdit_price");
    QLineEdit* le_RegNum = findChild<QLineEdit*>("lineEdit_RegNum");

    tmp_car->SetID(le_id->text().toInt());
    tmp_car->SetMARK(le_mark->text().toStdString());
    tmp_car->SetMODEL(le_model->text().toStdString());
    tmp_car->SetYEAR(le_year->text().toInt());
    tmp_car->SetCOLOR(t_color(le_color->text().toInt()));
    tmp_car->SetPRICE(le_price->text().toDouble());
    tmp_car->SetREGNUM(le_RegNum->text().toStdString());

    CarsStorage::Instance().push_back(tmp_car);
}

void QtWidgetsCarsPropViewer::show_frame_add_car()
{
    QFrame* fr_AddCar = findChild<QFrame*>("frame_AddCar");
    fr_AddCar->setVisible(true);

    QFrame* fr_ShowCars = findChild<QFrame*>("frame_ShowCars");
    fr_ShowCars->setVisible(false);

    apply_filter = false;
}
void QtWidgetsCarsPropViewer::show_frame_viewer_filter_year_price()
{
    Hide_Add_Show_Filter();

    apply_filter_C();

    QTableWidget* tableCar = findChild<QTableWidget*>("tableCars");

    RefreshTable(tableCar);

    FillTable(tableCar);

}

void QtWidgetsCarsPropViewer::FillTable(QTableWidget* tableCar)
{
    QLineEdit* le_mark_filter = findChild<QLineEdit*>("lineEdit_mark_filter");
    QLineEdit* le_model_filter = findChild<QLineEdit*>("lineEdit_model_filter");
    QLineEdit* le_year_filter = findChild<QLineEdit*>("lineEdit_year_filter");
    QLineEdit* le_year_more_filter = findChild<QLineEdit*>("lineEdit_year_more_filter");
    QLineEdit* le_price_filter = findChild<QLineEdit*>("lineEdit_price_filter");

    

    for (int i = 0; i < CarsStorage::Instance().size(); i++)
    {
        if (filter > filter_Zero && apply_filter)
        {
            if (filter == filter_A) 
                if(QString::fromUtf8(CarsStorage::Instance()[i]->GetMARK().c_str()) != le_mark_filter->text())                
                    continue;

            if (filter == filter_B)
                if (QString::fromUtf8(CarsStorage::Instance()[i]->GetMODEL().c_str()) != le_model_filter->text() ||
                    CarsStorage::Instance()[i]->GetYEAR() < le_year_more_filter->text().toInt())
                    continue;

            if (filter == filter_C)
                if (CarsStorage::Instance()[i]->GetYEAR() != le_year_filter->text().toInt() || 
                    CarsStorage::Instance()[i]->GetPRICE() <= le_price_filter->text().toDouble())
                    continue;
        }

        int row_num = tableCar->rowCount();

        tableCar->setRowCount(row_num + 1);

        QString tmp_id = QLocale().toString(CarsStorage::Instance()[i]->GetID());
        QTableWidgetItem* newItemID = new QTableWidgetItem(tmp_id);
        tableCar->setItem(row_num, 0, newItemID);

        QString tmp_mark = QString::fromUtf8(CarsStorage::Instance()[i]->GetMARK().c_str());
        QTableWidgetItem* newItemMARK = new QTableWidgetItem(tmp_mark);
        tableCar->setItem(row_num, 1, newItemMARK);

        QString tmp_model = QString::fromUtf8(CarsStorage::Instance()[i]->GetMODEL().c_str());
        QTableWidgetItem* newItemMODEL = new QTableWidgetItem(tmp_model);
        tableCar->setItem(row_num, 2, newItemMODEL);

        QString tmp_year = QLocale().toString(CarsStorage::Instance()[i]->GetYEAR());
        QTableWidgetItem* newItemYEAR = new QTableWidgetItem(tmp_year);
        tableCar->setItem(row_num, 3, newItemYEAR);

        QString tmp_color = QLocale().toString(int(CarsStorage::Instance()[i]->GetCOLOR()));
        QTableWidgetItem* newItemCOLOR = new QTableWidgetItem(tmp_color);
        tableCar->setItem(row_num, 4, newItemCOLOR);

        QString tmp_price = QLocale().toString(CarsStorage::Instance()[i]->GetPRICE());
        QTableWidgetItem* newItemPRICE = new QTableWidgetItem(tmp_price);
        tableCar->setItem(row_num, 5, newItemPRICE);

        QString tmp_regnum = QString::fromUtf8(CarsStorage::Instance()[i]->GetREGNUM().c_str());
        QTableWidgetItem* newItemREGNUM = new QTableWidgetItem(tmp_regnum);
        tableCar->setItem(row_num, 6, newItemREGNUM);

    }
}

void QtWidgetsCarsPropViewer::reset_filters_value()
{
    QLineEdit* le_mark_filter = findChild<QLineEdit*>("lineEdit_mark_filter");
    QLineEdit* le_model_filter = findChild<QLineEdit*>("lineEdit_model_filter");
    QLineEdit* le_year_filter = findChild<QLineEdit*>("lineEdit_year_filter");
    QLineEdit* le_year_more_filter = findChild<QLineEdit*>("lineEdit_year_more_filter");
    QLineEdit* le_price_filter = findChild<QLineEdit*>("lineEdit_price_filter");

    le_mark_filter->setText("");
    le_model_filter->setText("");
    le_year_filter->setText("");
    le_year_more_filter->setText("");
    le_price_filter->setText("");
}

void QtWidgetsCarsPropViewer::RefreshTable(QTableWidget* tableCar)
{
    tableCar->setRowCount(0);
    tableCar->setColumnCount(7);
    QStringList headers;
    headers << "ID" << "Mark" << "Model" << "Year" << "Color" << "Price" << "RegNum";
    tableCar->setHorizontalHeaderLabels(headers);
}

void QtWidgetsCarsPropViewer::apply_filter_A()
{
    QFrame* fr_filter_A = findChild<QFrame*>("frame_A");
    fr_filter_A->setVisible(true);

    QFrame* fr_filter_B = findChild<QFrame*>("frame_B");
    fr_filter_B->setVisible(false);

    QFrame* fr_filter_C = findChild<QFrame*>("frame_C");
    fr_filter_C->setVisible(false);

    reset_filters_value();
    filter = filter_A;
}

void QtWidgetsCarsPropViewer::apply_filter_B()
{
    QFrame* fr_filter_A = findChild<QFrame*>("frame_A");
    fr_filter_A->setVisible(false);

    QFrame* fr_filter_B = findChild<QFrame*>("frame_B");
    fr_filter_B->setVisible(true);

    QFrame* fr_filter_C = findChild<QFrame*>("frame_C");
    fr_filter_C->setVisible(false);

    reset_filters_value();
    filter = filter_B;
}

void QtWidgetsCarsPropViewer::apply_filter_C()
{
    QFrame* fr_filter_A = findChild<QFrame*>("frame_A");
    fr_filter_A->setVisible(false);

    QFrame* fr_filter_B = findChild<QFrame*>("frame_B");
    fr_filter_B->setVisible(false);

    QFrame* fr_filter_C = findChild<QFrame*>("frame_C");
    fr_filter_C->setVisible(true);

    reset_filters_value();
    filter = filter_C;
}

void QtWidgetsCarsPropViewer::clear_car_data()
{
    QLineEdit* le_id = findChild<QLineEdit*>("lineEdit_id");
    QLineEdit* le_mark = findChild<QLineEdit*>("lineEdit_mark");
    QLineEdit* le_model = findChild<QLineEdit*>("lineEdit_model");
    QLineEdit* le_year = findChild<QLineEdit*>("lineEdit_year");
    QLineEdit* le_color = findChild<QLineEdit*>("lineEdit_color");
    QLineEdit* le_price = findChild<QLineEdit*>("lineEdit_price");
    QLineEdit* le_RegNum = findChild<QLineEdit*>("lineEdit_RegNum");

    le_id->setText("");
    le_mark->setText("");
    le_model->setText("");
    le_year->setText("");
    le_color->setText("");
    le_price->setText("");
    le_RegNum->setText("");
}

void QtWidgetsCarsPropViewer::show_frame_viewer_filter_mark()
{
    Hide_Add_Show_Filter();

    apply_filter_A();

    QTableWidget* tableCar = findChild<QTableWidget*>("tableCars");

    RefreshTable(tableCar);

    FillTable(tableCar);
}

void QtWidgetsCarsPropViewer::show_frame_viewer_filter_model_price()
{
    Hide_Add_Show_Filter();

    apply_filter_B();

    QTableWidget* tableCar = findChild<QTableWidget*>("tableCars");

    RefreshTable(tableCar);

    FillTable(tableCar);
}

void QtWidgetsCarsPropViewer::apply_selected_filter()
{
    apply_filter = true;

    QTableWidget* tableCar = findChild<QTableWidget*>("tableCars");

    tableCar->setRowCount(0);

    FillTable(tableCar);
}
