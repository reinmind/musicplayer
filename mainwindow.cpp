#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);
    player->setVolume(ui->volume->value());
    playList = new QMediaPlaylist(this);
    playList->setPlaybackMode(QMediaPlaylist::Loop);
    playList->addMedia(QUrl::fromLocalFile("D:/MusicLib/AMAZING ME.mp3"));
    player->setPlaylist(playList);
//    connect(player,&QMediaPlayer::stateChanged,this,&MainWindow::stateChanged);
//    connect(player,&QMediaPlayer::positionChanged,this,&MainWindow::positionChanged);

}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::positionChanged(qint64 position)
//{
//    if(ui->timeProgress->maximum() != player->duration())
//        ui->timeProgress->setMaximum(player->duration());

//    //ui->timeProgress->setValue(position);

//    int seconds = (position/1000) % 60;
//    int minutes = (position/60000) % 60;
//    int hours = (position/3600000) % 24;
//    QTime time(hours,minutes,seconds);
//    ui->time->setText(time.toString());
//}

//void MainWindow::stateChanged(QMediaPlayer::State state)
//{
//    if(state == QMediaPlayer::PlayingState)
//    {
//        ui->playButton->setEnabled(false);
//        ui->pauseButton->setEnabled(true);
//        ui->stopButton->setEnabled(true);
//        ui->status->setText("playing");
//    }
//    else if(state == QMediaPlayer::PausedState)
//    {
//        ui->playButton->setEnabled(true);
//        ui->pauseButton->setEnabled(false);
//        ui->stopButton->setEnabled(true);
//        ui->status->setText("pause");
//    }
//    else if(state == QMediaPlayer::StoppedState)
//    {
//        ui->playButton->setEnabled(true);
//        ui->pauseButton->setEnabled(false);
//        ui->stopButton->setEnabled(false);
//        ui->status->setText("stopped");
//    }
//}

void MainWindow::on_playButton_clicked()
{
    player->play();
}


void MainWindow::on_pauseButton_clicked()
{
    player->pause();
}

void MainWindow::on_stopButton_clicked()
{
    player->stop();
}

void MainWindow::on_timeProgress_sliderMoved(int position)
{
    player->setPosition(position);
}

void MainWindow::on_volume_sliderMoved(int position)
{
    player->setVolume(position);
}

void MainWindow::on_actionOpenFile_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,"Select Audio File",qApp->applicationDirPath(),"*.mp3;;*.wav");
    QFileInfo fileInfo(fileName);


    playList->addMedia(QUrl::fromLocalFile(fileName));

    if(player->isMetaDataAvailable())
    {
        QString albumTitle = player->metaData(QMediaMetaData::AlbumTitle).toString();
        ui->songName->setText("Playing " + albumTitle );

    }

    player->setPlaylist(playList);

}
