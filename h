--dont execute more than once

---------------------------------------------------------------------------------------------
getgenv().size = Vector3.new(6,6,6) --change numbrs to whatevr u want | original - (8,8,8) (studs)
getgenv().toggleKey = Enum.KeyCode.M --change letter to whatevr u want | original - M
getgenv().teamCheckToggleKey = Enum.KeyCode.T --change letter to whatevr u want | original - T
getgenv().visibleToggleKey = Enum.KeyCode.V--change letter to whatevr u want | original - P
---------------------------------------------------------------------------------------------

--no touch beyond here

--variables
local toggle = false
local teamCheck = true
local visible = true
local UIS = game:GetService("UserInputService")

--functions
function giveHBE()
    for i, v in pairs(game.Players:GetPlayers()) do
        if v.Name ~= game.Players.LocalPlayer.Name then
            if v.TeamColor == game.Players.LocalPlayer.TeamColor then
                if teamCheck == false then
                    v.Character:WaitForChild("HumanoidRootPart").Size = size
                    v.Character:WaitForChild("HumanoidRootPart").BrickColor = v.TeamColor
                    v.Character:WaitForChild("HumanoidRootPart").Transparency = 0.5
                    v.Character:WaitForChild("HumanoidRootPart").CanCollide = false
                    v.Character:WaitForChild("HumanoidRootPart").Material = Enum.Material.ForceField

                    if visible == false then
                        v.Character:WaitForChild("HumanoidRootPart").Transparency = 1
                    end
                end
            else
                v.Character:WaitForChild("HumanoidRootPart").Size = size
                v.Character:WaitForChild("HumanoidRootPart").BrickColor = v.TeamColor
                v.Character:WaitForChild("HumanoidRootPart").Transparency = 0.5
                v.Character:WaitForChild("HumanoidRootPart").CanCollide = false
                v.Character:WaitForChild("HumanoidRootPart").Material = Enum.Material.ForceField

                if visible == false then
                    v.Character:WaitForChild("HumanoidRootPart").Transparency = 1
                end
            end
            v.Character:WaitForChild("Humanoid").Died:connect(function()
                v.Character:WaitForChild("HumanoidRootPart").CanCollide = false
            end)
        end
        if v.Character:WaitForChild("HumanoidRootPart").Size ~= size then
            v.Character:WaitForChild("HumanoidRootPart").Transparency = 1
        end
    end
end
function takeHBE()
    for i, v in pairs(game.Players:GetPlayers()) do
        if v.Name ~= game.Players.LocalPlayer.Name then
            v.Character:WaitForChild("HumanoidRootPart").Size = Vector3.new(2,2,1)
            v.Character:WaitForChild("HumanoidRootPart").Transparency = 1
            v.Character:WaitForChild("HumanoidRootPart").CanCollide = false
        end
    end
end
function giveHBETeam()
    for i, v in pairs(game.Players:GetPlayers()) do
        if v.Name ~= game.Players.LocalPlayer.Name then
            if v.TeamColor == game.Players.LocalPlayer.TeamColor then
                v.Character:WaitForChild("HumanoidRootPart").Size = size
                v.Character:WaitForChild("HumanoidRootPart").BrickColor = v.TeamColor
                v.Character:WaitForChild("HumanoidRootPart").Transparency = 0.5
                v.Character:WaitForChild("HumanoidRootPart").CanCollide = false
                v.Character:WaitForChild("HumanoidRootPart").Material = Enum.Material.ForceField

                if visible == false then
                    v.Character:WaitForChild("HumanoidRootPart").Transparency = 1
                end
            end
            v.Character:WaitForChild("Humanoid").Died:connect(function()
                v.Character:WaitForChild("HumanoidRootPart").CanCollide = false
            end)
        end
        if v.Character:WaitForChild("HumanoidRootPart").Size ~= size then
            v.Character:WaitForChild("HumanoidRootPart").Transparency = 1
        end
    end
end
function takeHBETeam()
    for i, v in pairs(game.Players:GetPlayers()) do
        if v.Name ~= game.Players.LocalPlayer.Name then
            if v.TeamColor == game.Players.LocalPlayer.TeamColor then
                v.Character:WaitForChild("HumanoidRootPart").Size = Vector3.new(2,2,1)
                v.Character:WaitForChild("HumanoidRootPart").Transparency = 1
                v.Character:WaitForChild("HumanoidRootPart").CanCollide = false
            end
        end
    end
end
function visibleOn()
    for i, v in pairs(game.Players:GetPlayers()) do
        v.Character:WaitForChild("HumanoidRootPart").Transparency = 0.5
        if v.Character:WaitForChild("HumanoidRootPart").Size ~= size then
            v.Character:WaitForChild("HumanoidRootPart").Transparency = 1
        end
    end
end
function visibleOff()
    for i, v in pairs(game.Players:GetPlayers()) do
        v.Character:WaitForChild("HumanoidRootPart").Transparency = 1
    end
end

--keybinds
UIS.InputBegan:connect(function(input, processed)
	if not processed then
		if input.KeyCode == toggleKey then
			toggle = not toggle

            if toggle == true then
                giveHBE()
            else
                takeHBE()
            end

		elseif input.KeyCode == teamCheckToggleKey then

            teamCheck = not teamCheck

            if teamCheck == true then
               takeHBETeam()
            else
                giveHBETeam()
            end

        elseif input.KeyCode == visibleToggleKey then
            visible = not visible

            if visible == true then
                visibleOn()
            else
                visibleOff()
            end

        end
	end
end)

--respawned
for i, v in pairs(game.Players:GetPlayers()) do
    if v.Name ~= game.Players.LocalPlayer.Name then
        v.CharacterAdded:Connect(function()
            if toggle == true then
                if v.TeamColor == game.Players.LocalPlayer.TeamColor then
                    if teamCheck == false then
                        giveHBETeam()
                    end
                else
                    giveHBE()
                end

                if visible == false then
                    v.Character:WaitForChild("HumanoidRootPart").Transparency = 1
                end
            end
            v.Character:WaitForChild("Humanoid").Died:connect(function()
                v.Character:WaitForChild("HumanoidRootPart").CanCollide = false
            end)
        end)
    end
    if v.Character:WaitForChild("HumanoidRootPart").Size ~= size then
        v.Character:WaitForChild("HumanoidRootPart").Transparency = 1
    end
end
game.Players.PlayerAdded:Connect(function(addPlr)
    addPlr.CharacterAdded:Connect(function(addChr)
        if toggle == true then
             if addPlr.TeamColor == game.Players.LocalPlayer.TeamColor then
                    if teamCheck == false then
                        giveHBETeam()
                    end
                else
                    giveHBE()
                end

            if visible == false then
                 addChr:WaitForChild("HumanoidRootPart").Transparency = 1
            end
        end
        addChr:WaitForChild("Humanoid").Died:connect(function()
            addChr:WaitForChild("HumanoidRootPart").CanCollide = false
        end)
        if addChr:WaitForChild("HumanoidRootPart").Size ~= size then
            addChr:WaitForChild("HumanoidRootPart").Transparency = 1
        end
    end)
end)
