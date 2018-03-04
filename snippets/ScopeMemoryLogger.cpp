//logs to QStringList and saves stat about calls

QMap<QString, int> g_count;
QStringList g_str;
struct ScopeMemLogger {
    QString _name;
    void write(const QString & str) {
       g_str.prepend(str);
    }
    QElapsedTimer _timer;
    ScopeMemLogger(const QString & str): _name(str) {
        g_count[str]++;
        _timer.start();
        write("start " + _name);
    }
    ~ScopeMemLogger() {
        write(QString("finished ms=%1 ").arg(_timer.elapsed()) + _name);
    }
};
