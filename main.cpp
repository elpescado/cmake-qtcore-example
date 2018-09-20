#include <QDebug>
#include <QString>

QString getCompiler()
{
#if defined(_MSC_VER)
	return QString("MSVC %1.%2")
		.arg(_MSC_VER / 100)
		.arg(_MSC_VER % 100);
#elif defined(__clang__)
	return QString("Clang %1.%2.%3")
		.arg(__clang_major__)
		.arg(__clang_minor__)
		.arg(__clang_patchlevel__);
#elif defined(__GNUC__)
	#if defined(__MINGW__)
		QString name = "MinGW";
	#else
		QString name = "GCC"
	#endif
	return QString("%1 %2.%3.%4")
		.arg(name)
		.arg(__GNUC__)
		.arg(__GNUC_MINOR__)
		.arg(__GNUC_PATCHLEVEL__);
#endif
	return "???";
}

int main()
{
	QString compiler = getCompiler();
	int bits = sizeof(void*) * 8;
	qDebug() << "Hello from " << compiler << " (" << bits << " bit)";
	return 0;
}
