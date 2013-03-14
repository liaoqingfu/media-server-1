#include "log.h"
#include "audio.h"
#include "g711/g711codec.h"
#include "gsm/gsmcodec.h"
#include "speex/speexcodec.h"
#include "nelly/NellyCodec.h"


AudioEncoder* AudioCodecFactory::CreateEncoder(AudioCodec::Type codec)
{
	Log("-CreateAudioCodec [%d,%s]\n",codec,AudioCodec::GetNameFor(codec));

	//Creamos uno dependiendo del tipo
	switch(codec)
	{
		case AudioCodec::GSM:
			return new GSMEncoder();
		case AudioCodec::PCMA:
			return new PCMAEncoder();
		case AudioCodec::PCMU:
			return new PCMUEncoder();
		case AudioCodec::SPEEX16:
			return new SpeexEncoder();
		case AudioCodec::NELLY8:
			return new NellyEncoder();
		case AudioCodec::NELLY11:
			return new NellyEncoder11Khz();
		default:
			Error("Codec not found [%d]\n",codec);
	}

	return NULL;
}

AudioDecoder* AudioCodecFactory::CreateDecoder(AudioCodec::Type codec)
{
	Log("-CreateAudioCodec [%d,%s]\n",codec,AudioCodec::GetNameFor(codec));

	//Creamos uno dependiendo del tipo
	switch(codec)
	{
		case AudioCodec::GSM:
			return new GSMDecoder();
		case AudioCodec::PCMA:
			return new PCMADecoder();
		case AudioCodec::PCMU:
			return new PCMUDecoder();
		case AudioCodec::SPEEX16:
			return new SpeexDecoder();
		case AudioCodec::NELLY8:
			return NULL;
		case AudioCodec::NELLY11:
			return new NellyDecoder11Khz();
		default:
			Error("Codec not found [%d]\n",codec);
	}

	return NULL;
}