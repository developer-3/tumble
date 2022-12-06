# Todo

### ECS

Entities are objects that are effected by components (i.e. forces)

Components are forces

Systems are made up of entities and components, they compute how their components effect their entities and their entities' forces.



## <u>Systems</u>

System : class

- [x] Instantiate an empty System
- [x] Instantiate System with Entities and/or with Components
- [ ] Add Entities/Components to System
- [ ] Delete Entities/Components from System
- [ ] Update Entities based on Components and ∆t


## <u>Entities</u>

Entity : class

- [ ] Instantiate massless, empty Entity
- [ ] Instantiate Entity with mass
- [ ] Entities can be defined by mass and shape.
- [ ] Entities can update their position and rotation by their Components.
- [ ] Entities can have Components.


## <u>Components</u>

Component : abstract class

- [ ] A component has a defined force.
- [ ] A component can perform a computation based on inputted information about an entity and return the result.
- [ ] Instantiate a component with or without given parameters.
- [ ] Components have parameters that affect the computation.
- [ ] Parameters of components can be updated after instantiation.
