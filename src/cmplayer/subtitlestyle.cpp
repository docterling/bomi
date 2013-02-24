#include "subtitlestyle.hpp"
#include "record.hpp"

void SubtitleStyle::save(Record &r, const QString &group) const {
	r.beginGroup(group);
#define WRITE(a) r.write(a, #a)
	WRITE(font.color);
	WRITE(font.size);
	WRITE(font.scale);
	WRITE(font.qfont);
	WRITE(outline.enabled);
	WRITE(outline.color);
	WRITE(outline.width);
	WRITE(shadow.enabled);
	WRITE(shadow.color);
	WRITE(shadow.blur);
	WRITE(shadow.offset);
	WRITE(spacing.line);
	WRITE(spacing.paragraph);
#undef WRITE
	r.endGroup();
}

void SubtitleStyle::load(Record &r, const QString &group) {
	r.beginGroup(group);
#define READ(a) r.read(a, #a)
	READ(font.color);
	READ(font.size);
	READ(font.scale);
//	READr.read((int&)font.scale, "font.scale");
	READ(font.qfont);
	READ(outline.enabled);
	READ(outline.color);
	READ(outline.width);
	READ(shadow.enabled);
	READ(shadow.color);
	READ(shadow.blur);
	READ(shadow.offset);
	READ(spacing.line);
	READ(spacing.paragraph);
#undef READ
	r.endGroup();

	// for < 0.6.0 compatibility
//	shadow_offset.rx() = qBound(-0.01, shadow_offset.x(), 0.01);
//	shadow_offset.ry() = qBound(-0.01, shadow_offset.y(), 0.01);
}