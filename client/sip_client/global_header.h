#ifndef GLOBAL_HEADER_H
#define GLOBAL_HEADER_H

#include <QObject>
#include <vector>
#include <string>
#include <algorithm>
#include <eXosip2/eXosip.h>
#include <osip2/osip_mt.h>
using std::vector;
using std::string;
using std::tuple;
class global_header : public QObject
{
	Q_OBJECT

public:
	global_header(QObject *parent);
	~global_header();
	static vector<string>& return_audio_support_name();
	static vector<string>& return_video_support_name();
	static std::map<string, eXosip_event_t*>& return_id_string();
	static std::string& return_audio();
	static std::string& return_video();
	static std::tuple<string, string, string, string>& return_ring_detail();
	//static vector<string>& return_audio_support_name();
	//static vector<string>& return_audio_support_name();
private:
	
	
};

#endif // GLOBAL_HEADER_H
