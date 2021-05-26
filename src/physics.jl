include("typesnutil.jl")

# sample function
function gravity(time::Float64, pos::Point)
    # julia pog
    new_pos = pos.y + (0.5)*γ*t
    return new_pos
end
