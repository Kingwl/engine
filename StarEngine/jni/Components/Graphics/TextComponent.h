#pragma once

#include "../../defines.h"
#include "../BaseComponent.h"
#include "../../Graphics/Color.h"
#include <vector>

namespace star
{
	class Font;
	class TextComponent : public BaseComponent
	{
	public:
		TextComponent(const tstring& fileName,const tstring& tag, int fontSize, bool bInFront = true);
		virtual ~TextComponent();

		void Draw();
		virtual void Update(const Context& context);
		void SetText(const tstring& text);
		const tstring& GetText() const;
		void SetColor(const Color& color);
		const Color& GetColor() const;
		//Default set to -1, Set width to -1 to disable wrapping
		void SetWrapWidth(float width);
		float GetWrapWidth() const;
		
	protected:
		virtual void InitializeComponent();
	
	private:
		int32 m_FontSize;
		tstring m_FileName;
		tstring m_FontName;

		Color m_TextColor;
		float m_MaxWidth;
		tstring m_OrigText;
		tstring m_EditedText;

		bool m_bCheckedWrapping, 
			 m_bInFront;

		tstring CheckWrapping(const Font& font, const tstring& stringIn, float wrapWidth);
		void SplitString(std::vector<tstring>& wordArrayIn,const tstring& stringIn, const tstring& delimiter);

		TextComponent(const TextComponent &);
		TextComponent(TextComponent &&);
		TextComponent & operator=(const TextComponent &);
	};
}