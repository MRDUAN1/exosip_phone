#include "global_header.h"
static vector<string>audio_support_name;
static vector<string>video_support_name;
static string video_str, audio_str;
//音频，视频， ip地址， 端口号
static std::tuple<string , string, string, string>globa_detail; //保存menu的设置的数据
static std::map<string, eXosip_event_t*>call_id_string;
global_header::global_header(QObject *parent)
	: QObject(parent)
{

}
std::map<string, eXosip_event_t*>& global_header::return_id_string()
{
	return call_id_string;
}
vector<string>& global_header::return_audio_support_name()
{
	return audio_support_name;
}
vector<string>& global_header::return_video_support_name()
{
	return video_support_name;
}
global_header::~global_header()
{

}
std::string& global_header::return_audio()
{
	return audio_str;
}
std::string& global_header::return_video()
{
	return video_str;
}
std::tuple<string, string, string, string>& global_header::return_ring_detail()
{
	return globa_detail;
}
