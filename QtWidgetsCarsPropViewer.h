#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtWidgetsCarsPropViewer.h"
#include "CarsStorage.h"

enum checked_filter { filter_Zero, filter_A, filter_B, filter_C };

class QtWidgetsCarsPropViewer : public QMainWindow
{
    Q_OBJECT

public:
    QtWidgetsCarsPropViewer(QWidget *parent = nullptr);
    ~QtWidgetsCarsPropViewer();

    void Hide_Add_Show_Filter();
    void RefreshTable(QTableWidget* tableCar);
    void apply_filter_A();
    void apply_filter_B();
    void apply_filter_C();
    void FillTable(QTableWidget* tableCar);
    void reset_filters_value();

private slots:
    void add_new_car();
    void show_frame_add_car();
    void show_frame_viewer_filter_year_price();
    void clear_car_data();
    void show_frame_viewer_filter_mark();
    void show_frame_viewer_filter_model_price();
    void apply_selected_filter();

private:
    Ui::QtWidgetsCarsPropViewerClass ui;
    checked_filter filter;
    bool apply_filter;
};
