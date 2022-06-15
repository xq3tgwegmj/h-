getgenv().size = Vector3.new(6,6,6)
getgenv().toggle = false
getgenv().teamCheck = true
getgenv().visible = true

--Functions
function giveHBE()
    for _, v in pairs(game.Players:GetPlayers()) do
        if v.Name ~= game.Players.LocalPlayer.Name then
            if v.Character then
                if v.Character:FindFirstChild("HumanoidRootPart") then
                    if not getgenv().teamCheck then
                        v.Character.HumanoidRootPart.Size = getgenv().size
                        v.Character.HumanoidRootPart.CanCollide = false
                        v.Character.HumanoidRootPart.BrickColor = v.TeamColor
                        v.Character.HumanoidRootPart.Material = Enum.Material.ForceField
                        if getgenv().visible then
                            v.Character.HumanoidRootPart.Transparency = 0.6
                        else
                            v.Character.HumanoidRootPart.Transparency = 1
                        end
                    else
                        if v.TeamColor ~= game.Players.LocalPlayer.TeamColor then
                            v.Character.HumanoidRootPart.Size = getgenv().size
                            v.Character.HumanoidRootPart.CanCollide = false
                            v.Character.HumanoidRootPart.BrickColor = v.TeamColor
                            v.Character.HumanoidRootPart.Material = Enum.Material.ForceField
                            if getgenv().visible then
                                v.Character.HumanoidRootPart.Transparency = 0.6
                            else
                                v.Character.HumanoidRootPart.Transparency = 1
                            end
                        end
                    end
                end
            end
        end
    end
end
function takeHBE()
    for _, v in pairs(game.Players:GetPlayers()) do
        if v.Character then
            if v.Character:FindFirstChild("HumanoidRootPart") then 
                v.Character.HumanoidRootPart.Size = Vector3.new(2,2,1)
                v.Character.HumanoidRootPart.CanCollide = false
                v.Character.HumanoidRootPart.Transparency = 1
            end
        end
    end
end
--char added
for _, v in pairs(game.Players:GetPlayers()) do
    v.CharacterAdded:Connect(function()
        if getgenv().toggle then
            giveHBE()
        end
    end)
end
--player added
game.Players.PlayerAdded:Connect(function(p)
    if getgenv().toggle then
        giveHBE()
    end
    p.CharacterAdded:Connect(function()
        if getgenv().toggle then
            giveHBE()
        end
    end)
end)

function visibleOn()
    for _, v in pairs(game.Players:GetPlayers()) do
        if v.Name ~= game.Players.LocalPlayer.Name then
            if v.Character:FindFirstChild("HumanoidRootPart") then
                v.Character.HumanoidRootPart.Transparency = 0.6
            end
        end
    end
end
function visibleOff()
    for _, v in pairs(game.Players:GetPlayers()) do
        if v.Character:FindFirstChild("HumanoidRootPart") then 
            v.Character.HumanoidRootPart.Transparency = 1
        end
    end
end
