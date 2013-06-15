#include "usettingsreader.h"

#include <QSettings>
#include <QStringList>

#include <QDebug>

///////////////////////////////////////////////////////////////////////////////////////////////////////////
USettingsReader::USettingsReader()
{
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
void USettingsReader::readSettings(const QString &fileName)
{
    QSettings settings(fileName, QSettings::IniFormat);
    SSettingsInfo currSetting;

//    for (int i = 0; i < settings.childGroups().size(); i++) {
//        currSetting.fileName = settings.childGroups().at(i);
//        currSetting.link = settings.value(currSetting.fileName + "/link").toString();
//        currSetting.hash = settings.value(currSetting.fileName + "/md5").toByteArray();

//        m_readSettings[currSetting.fileName] = currSetting;
//    }

    QString tmp;
    int indx;
    for (int i = 0; i < settings.allKeys().size(); i += 2) {
        tmp = settings.allKeys().at(i);

        indx = tmp.indexOf("/link");

        currSetting.fileName = tmp.remove(indx, tmp.size() - indx);
        currSetting.link = settings.value(currSetting.fileName + "/link").toString();
        currSetting.hash = settings.value(currSetting.fileName + "/md5").toByteArray();

        m_readSettings[currSetting.fileName] = currSetting;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
TReadSettings USettingsReader::getSettings()
{
    return m_readSettings;
}



