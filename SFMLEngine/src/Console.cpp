#include "Console.h"
#include <memory>

void Console::AddMessage(const std::string& message)
{
	messages.push_back(std::make_unique<std::string>(message));
}

void Console::Draw()
{
	ImGui::Begin("Console");
	ImGui::BeginChild("Scroll", ImVec2(ImGui::GetContentRegionAvail().x,
		ImGui::GetContentRegionAvail().y), false,
		ImGuiWindowFlags_HorizontalScrollbar);
	for(const auto& message : this->messages)
	{
		ImGui::Text("%s", message->c_str());
	}
	ImGui::EndChild();
	ImGui::End();
}