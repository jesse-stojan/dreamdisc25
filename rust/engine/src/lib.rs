// Minimal Rust Engine prototype for DreamDisk25

pub struct Engine {
    pub name: &'static str,
}

impl Engine {
    pub fn new() -> Self {
        Self { name: "DreamDisk25 Engine (Rust)" }
    }

    pub fn run(&self) {
        println!("{} running", self.name);
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn engine_runs() {
        let e = Engine::new();
        e.run();
    }
}
