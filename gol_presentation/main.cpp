#include <QGuiApplication>
#include <QList>
#include <QMetaType>
#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlEngine>
#include <QScopedPointer>
#include <QString>
#include <QVariant>

#include "GolModel.h"

Q_DECLARE_METATYPE(QList<CellModel*>)

int main(int argc, char* argv[])
{
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QGuiApplication app(argc, argv);

	qmlRegisterType<GolModel>("GolModel", 1, 0, "GolModel");

	QQmlApplicationEngine engine;
	engine.load(QUrl(QStringLiteral("qrc:/Gol.qml")));

	if (engine.rootObjects().isEmpty())
	{
		return -1;
	}

	return app.exec();
}
